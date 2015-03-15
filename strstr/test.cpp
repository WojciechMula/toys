#include <string>

#include <assert.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

const size_t NOT_FOUND = ~(size_t(0));

typedef size_t (strstr_fun)(const char* s, size_t size, const char* neddle);

#include "strstr-libc.cpp"
#include "strstr-stdstring.cpp"

#ifdef TEST64
#	include "strstr64.cpp"
#else
#	include "strstr32.cpp"
#endif

struct environment_t {
	std::string data;
	std::string neddle;

	environment_t(FILE* f) {
		fseek(f, -1, SEEK_END);
		auto size = ftell(f);
		fseek(f, 0, SEEK_SET);

		data.resize(size);
		fread((void*)data.data(), size, 1, f);

		fclose(f);
	}

	void set_neddle(char* _neddle) {
		neddle = _neddle;
	}
};

struct measure_result_t {
	std::string  name;
	int          result;
	double		 time;

	void print() {
		printf("%10s: result=%9d, time=%0.7f",
			name.c_str(),
			result,
			time
		);
	}

	void println() {
		print();
		putchar('\n');
	}

	double speedup(const measure_result_t& other) const {
		if (time <= other.time)
			return other.time/time;
		else
			return -time/other.time;
	}

	void print_speedup(const measure_result_t& other) const {
		const auto s = speedup(other);

		if (s > 0.0)
			printf("faster %0.3f", s);
		else if (s < 0.0)
			printf("slower %0.3f", s);
		else
			printf("same speed");
	}
};

uint32_t get_time(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}


const int iterations = 10;


measure_result_t measure(const std::string& name, strstr_fun fun, environment_t& env) {
	measure_result_t res;

	auto t1  = get_time();

	int i = iterations;
	while (i--) {
		res.result = fun(env.data.c_str(), env.data.size(), env.neddle.c_str());
	}

	auto t2  = get_time();

	res.name = name;
	res.time = (t2 - t1)/1000000.0;

	return res;
}


measure_result_t measure(const std::string& name, environment_t& env) {
	measure_result_t res;

	auto t1  = get_time();

	int i = iterations;
	while (i--) {
		res.result = strstr_stdstring(env.data, env.neddle);
	}
	auto t2  = get_time();

	res.name = name;
	res.time = (t2 - t1)/1000000.0;

	return res;
}

void usage(const char* progname) {
	printf("%s filename pattern1 [patterns...]\n", progname);
}


void print_comparision(const measure_result_t& m1, const measure_result_t& m2) {
	printf("%s/%s: ", m1.name.c_str(), m2.name.c_str());
	m1.print_speedup(m2);
	putchar('\n');
}


int main(int argc, char* argv[]) {
	if (argc == 1) {
		usage(argv[0]);
		return EXIT_FAILURE;
	}

	FILE* file = fopen(argv[1], "rb");
	if (file == nullptr) {
		printf("File '%s' not found or can't be read\n", argv[1]);
		return EXIT_FAILURE;
	}

	environment_t env(file);

	for (auto i = 2; i < argc; i++) {
		env.set_neddle(argv[i]);
		printf("searching for '%s' in %lu bytes...\n", env.neddle.c_str(), env.data.size());

		auto libc   = measure("libc",   strstr_libc, env);
		auto cpp    = measure("c++",    env);
#ifdef TEST64
		auto custom = measure("custom (64-bit)", strstr64, env);
#else
		auto custom = measure("custom (32-bit)", strstr32, env);
#endif

		libc.println();
		cpp.println();
		custom.println();

		print_comparision(custom, libc);
		print_comparision(custom, cpp);
	}

	return EXIT_SUCCESS;
}
