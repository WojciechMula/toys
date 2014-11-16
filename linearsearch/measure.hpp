#ifndef MEASURE_HPP_INCLUDED__
#define MEASURE_HPP_INCLUDED__

#include <string>
#include <vector>
#include <map>
#include <algorithm>


template <typename Object>
class Collection {

protected:
    std::vector<Object*> objects;
    std::map<std::string, Object*> name2object;

public:
    Object& add(const std::string& name) {
        auto obj = new Object(name);

        name2object[name] = obj;
        objects.push_back(obj);

        return *obj;
    }


    bool has(const std::string& name) const {

        return name2object.count(name);
    }


    Object& operator[](const std::string& name) const {

        return *name2object.find(name)->second;
    }


    typename std::vector<Object*>::iterator begin() {
        return objects.begin();
    }


    typename std::vector<Object*>::iterator end() {
        return objects.end();
    }
};


class NamedEntity {
public:
    const std::string name;

public:
    NamedEntity(const std::string& name) : name(name) {}
};


class Timer: public NamedEntity {

    std::vector<double> samples;

public:
    Timer(const std::string& name): NamedEntity(name) {}

public:
    void push_back(double sample) {
        samples.push_back(sample);
    }

    double min() const {
        return *std::min_element(begin(samples), end(samples));
    }

    double max() const {
        return *std::max_element(begin(samples), end(samples));
    }

    double sum() const {
        auto result = 0.0;
        for (auto sample: samples) {
            result += sample;
        }

        return result;
    }

    double avg() const {
        return sum()/count();
    }

    std::size_t count() const {
        return samples.size();
    }
};

class Object: public NamedEntity, public Collection<Timer> {

public:
    Object(const std::string& name) : NamedEntity(name) {}
};


class Measure: public Collection<Object> {
};


template <typename Storage>
class scoped_timer {
    Storage& storage;
    const uint32_t t_start;
    uint32_t t_stop;
public:
    scoped_timer(Storage& s)
        : storage(s)
        , t_start(get_time())
        , t_stop(0) {}


    void stop() {
        if (t_stop != 0) {
            return;
        }

        t_stop = get_time();

        storage.push_back(in_seconds(t_stop));
    }


    double in_seconds(uint32_t time) {
        return (time - t_start)/1000000.0;
    }


    double in_seconds() {
        return in_seconds(get_time());
    }


    ~scoped_timer() {
        stop();
    }

private:
    uint32_t get_time(void) {
        static struct timeval T;
        gettimeofday(&T, NULL);

        return (T.tv_sec * 1000000) + T.tv_usec;
    }
};

#endif
