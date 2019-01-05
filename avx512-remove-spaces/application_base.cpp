class ApplicationBase {

protected:
    static const size_t size = 64;
    char input[size];
    char output[size];

protected:
    uint64_t random(int cardinality) {
        uint64_t v = 0;
        while (__builtin_popcountll(v) != cardinality) {
            v |= uint64_t(1) << (rand() % 64);
        }

        return v;
    }

    void init_input() {
        int i=0;
        for (int j='a'; j <= 'z'; j++)
            input[i++] = j;

        for (int j='A'; j <= 'Z'; j++)
            input[i++] = j;

        for (int j='0'; j <= '9'; j++)
            input[i++] = j;

        input[i++] = '#';
        input[i++] = '@';

        assert(i == size);
    }
};

