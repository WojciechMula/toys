#include <sys/time.h>


class measure_item_t {
    const std::string name;
    uint32_t t1, t2;

public:
    measure_item_t(const std::string& name) : name(name) {}

public:
    void print() const {
        std::printf("%20s: %10.4fs\n", name.c_str(), get_time());
    }

    void print(const measure_item_t& other) const {
        std::printf("%20s: %10.4fs (speedup: %0.2f)\n", name.c_str(), get_time(), other.get_time()/get_time());
    }

	double get_time() const {
		return (t2 - t1)/1000000.0;
	}

	void start() {
		t1 = get_time();
	}

	void stop() {
		t2 = get_time();
	}

private:
	uint32_t get_time(void) {
		static struct timeval T;
		gettimeofday(&T, NULL);
		return (T.tv_sec * 1000000) + T.tv_usec;
	}
};


template <typename Middle>
std::size_t count(const ArrayType& array, Middle middle, const std::string& name) {

    std::size_t count = 0;
    auto middle_wrapper = [&](std::size_t a, std::size_t b, const ArrayType& array, int key) {
        count += 1;
        
        return middle(a, b, array, key);
    };

    const auto n = array.size();

    for (auto i=0u; i < n; i++) {
        search(array, i, middle_wrapper);
    }

    std::printf("%20s: %d, avg %0.2f\n", name.c_str(), count, count/double(n));

    return count;
}


template <typename Middle>
measure_item_t speed(const ArrayType& array, Middle middle, const std::string& name) {

    measure_item_t m(name);
    m.start();

    const auto n = array.size();
    for (auto i=0u; i < n; i++) {
        search(array, i, middle);
    }

    m.stop();
    m.print();

    return m;
}


template <typename Value, typename... Args>
ArrayType prepare(std::size_t n, Value value, Args... args) {

    ArrayType array(n);

    for (auto i=0; i < n; i++) {
        array[i] = value(i, n, args...);
    }

    for (auto i=1; i < n; i++) {
        assert(array[i - 1] <= array[i]);
    }

    return array;
}


namespace distribution {


int linear(int i, int /* n */) {
    return i;
}


int linear_flat(int i, int n, int range) {

    double t = i/double(n);

    return range * t;
}


int square(int i, int n) {

    double t = i/double(n);
    
    return n * (t * t);
}


int square_root(int i, int n) {

    double t = i/double(n);

    return n * (std::sqrt(t));
}



int square_root_flat(int i, int n, double coef) {

    double t = i/double(n);

    return n * (coef * std::sqrt(t));
}


int power(int i, int n, double k) {

    double t = i/double(n);

    return n * pow(t, k);
}


} // namespace distribution
