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
#include "strstr32.cpp"

struct environment_t {
	char*  data;
	size_t size;
	char*  neddle;
	size_t neddle_size;

	environment_t(size_t size) : size(size), neddle(nullptr), neddle_size(0) {
		data = static_cast<char*>(malloc(size + 1));

		memset(data, '?', size);
		data[size] = '\0';
	}

	~environment_t() {
		free(data);
	}

	void set_neddle(char* _neddle) {
		assert(_neddle != nullptr);

		// clear previous needle data
		memset(&data[size - neddle_size - 1], '?', neddle_size);

		// set new one
		neddle_size = strlen(_neddle); 
		neddle = _neddle;

		memcpy(&data[size - neddle_size - 1], neddle, neddle_size);
	}
};

struct measure_result_t {
	std::string  name;
	int          result;
	double		 time;

	void print() {
		printf("%10s: result=%9d, time=%0.4f\n",
			name.c_str(),
			result,
			time
		);
	}
};

uint32_t get_time(void) {
	static struct timeval T;
	gettimeofday(&T, NULL);
	return (T.tv_sec * 1000000) + T.tv_usec;
}


measure_result_t measure(const std::string& name, strstr_fun fun, environment_t& env) {
	measure_result_t res;

	auto t1  = get_time();
	res.result = fun(env.data, env.size, env.neddle);
	auto t2  = get_time();

	res.name = name;
	res.time = (t2 - t1)/1000000.0;

	return res;
}

int main(int argc, char* argv[]) {
	const size_t MiB = 1024*1024;

	environment_t env(16*MiB);

	for (auto i = 1; i < argc; i++) {
		env.set_neddle(argv[i]);
		printf("searching for '%s' in %d bytes...\n", env.neddle, env.size);

		auto m1 = measure("libc",   strstr_libc, env);
		auto m2 = measure("custom", strstr32, env);

		m1.print();
		m2.print();
	}
}
