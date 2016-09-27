class InputData {
    
protected:
    uint32_t*   array;
    size_t      n;

public:
    InputData(size_t count)
        : n(count) {

        assert(n > 0);
        array = new uint32_t[n];
    }

    ~InputData() {
        delete[] array;
    }

public:
    uint32_t* pointer() {
        return array;
    }

    size_t count() const {
        return n;
    }

    size_t size() const {
        return n * sizeof(uint32_t);
    }
};


class InputAscending: public InputData {

    using super = InputData;

public:
    InputAscending(size_t count) : super(count) {
        for (size_t i=0; i < n; i++) {
            array[i] = i;
        }
    }
};


class InputDescending: public InputData {

    using super = InputData;

public:
    InputDescending(size_t count) : super(count) {
        for (size_t i=0; i < n; i++) {
            array[i] = n - i + 1;
        }
    }
};

class InputRandomFew: public InputData {

    using super = InputData;

public:
    InputRandomFew(size_t count) : super(count) {
        for (size_t i=0; i < n; i++) {
            array[i] = random() % 10;
        }
    }
};

class InputRandom: public InputData {

    using super = InputData;

public:
    InputRandom(size_t count) : super(count) {
        for (size_t i=0; i < n; i++) {
            array[i] = random();
        }
    }
};

