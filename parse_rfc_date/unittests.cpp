#include <set>
#include <string>
#include <functional>
#include <cstdio>
#include <cstring>

#if TEST_SCALAR
#   include "scalar.cpp"
#else
    #if TEST_KENDALL
    #   include "sse_kendall.cpp"
    #else
    #   include "sse.cpp"
    #endif
#endif

static const char* weekdays[] = {"Sun", "Mon", "Tue",
                                 "Wed", "Thu", "Fri",
                                 "Sat"};

static const char* months[]   = {"Jan", "Feb", "Mar",
                                 "Apr", "May", "Jun",
                                 "Jul", "Aug", "Sep",
                                 "Oct", "Nov", "Dec"};

class TestBase {

protected:
    enum {
        WEEKDAY0    = 0,
        WEEKDAY1    = 1,
        WEEKDAY2    = 2,

        DAY0        = 5,
        DAY1        = 6,

        MONTH0      = 8,
        MONTH1      = 9,
        MONTH2      = 10,

        YEAR0       = 12,
        YEAR1       = 13,
        YEAR2       = 14,
        YEAR3       = 15,

        HOUR0       = 17,
        HOUR1       = 18,

        MINUTE0     = 20,
        MINUTE1     = 21,

        SECOND0     = 23,
        SECOND1     = 24
    };


protected:
    const std::string valid_pattern;
    std::string pattern;
    tm result;
    char tmp[32];

    class TestFailed: public std::logic_error {
    public:
        TestFailed(const std::string& msg) : std::logic_error(msg) {}
    };

public:
    TestBase() : valid_pattern("Fri, 17 Apr 2015 16:14:11 GMT") {}

protected:
    template <typename FUN>
    void test(const char* name, FUN fun) {
        printf("%s ", name);
        fflush(stdout);
        fun();
        puts("OK");
    }

    void assume_valid_invocation();
    void assume_invalid_invocation();
    int  invocation();
};

class TestValidConversion: public TestBase {

public:
    bool test_all();

private:
    void test_parse_weekday();
    void test_parse_month_name();
    void test_parse_year();
    void test_parse_day();
    void test_parse_hour();
    void test_parse_minute();
    void test_parse_second();

    template <typename FUN>
    void test(const char* name, FUN fun) {
        printf("%s", name);
        fflush(stdout);
        fun();
        puts(" OK");
    }
};


int TestBase::invocation() {
#ifdef TEST_SCALAR
    return parse_rfc_date_reference(pattern.c_str(), &result);
#else
#ifdef TEST_KENDALL
    return parse_rfc_date_kendall(pattern.c_str(), &result);
#else
    return parse_rfc_date(pattern.c_str(), &result);
#endif
#endif
}


void TestBase::assume_valid_invocation() {
    const int ret = invocation();
    if (ret < 0) {
        throw TestFailed{"Expected proper conversion, got " + std::to_string(ret)};
    }
}


void TestBase::assume_invalid_invocation() {
    const int ret = invocation();
    if (ret == 0) {
        throw TestFailed{"Expected detection of error"};
    }
}


bool TestValidConversion::test_all() {
    try {
        test("Parse weekday",       std::bind(&TestValidConversion::test_parse_weekday, this));
        test("Parse month name",    std::bind(&TestValidConversion::test_parse_month_name, this));
        test("Parse year",          std::bind(&TestValidConversion::test_parse_year, this));
        test("Parse day",           std::bind(&TestValidConversion::test_parse_day, this));
        test("Parse hour",          std::bind(&TestValidConversion::test_parse_hour, this));
        test("Parse minute",        std::bind(&TestValidConversion::test_parse_minute, this));
        test("Parse second",        std::bind(&TestValidConversion::test_parse_second, this));
        return true;
    } catch (TestFailed& e) {
        puts(e.what());
        printf("pattern = '%s'\n", pattern.c_str());
        return false;
    }
}

void TestValidConversion::test_parse_weekday() {

    for (int i=0; i < 7; i++) {
        result.tm_wday = -1;
        pattern = valid_pattern;
        pattern[WEEKDAY0] = weekdays[i][0];
        pattern[WEEKDAY1] = weekdays[i][1];
        pattern[WEEKDAY2] = weekdays[i][2];

        assume_valid_invocation();

        if (result.tm_wday != i) {
            throw TestFailed{"Invalid weekday"};
        }
    }
}

void TestValidConversion::test_parse_month_name() {

    for (int i=0; i < 12; i++) {
        result.tm_mon = -1;
        pattern = valid_pattern;
        pattern[MONTH0] = months[i][0];
        pattern[MONTH1] = months[i][1];
        pattern[MONTH2] = months[i][2];

        assume_valid_invocation();

        if (result.tm_mon != i) {
            throw TestFailed{"Invalid month name"};
        }
    }
}


void TestValidConversion::test_parse_year() {

    for (int i=1900; i <= 2900; i++) {

        snprintf(tmp, sizeof(tmp), "%d", i);
        result.tm_year = -1;
        pattern = valid_pattern;
        pattern[YEAR0] = tmp[0];
        pattern[YEAR1] = tmp[1];
        pattern[YEAR2] = tmp[2];
        pattern[YEAR3] = tmp[3];

        assume_valid_invocation();

        if (result.tm_year != i - 1900) {
            throw TestFailed{"Invalid year"};
        }
    }
}

void TestValidConversion::test_parse_day() {

    for (int i=1; i <= 31; i++) {

        snprintf(tmp, sizeof(tmp), "%02d", i);
        result.tm_mday = -1;
        pattern = valid_pattern;
        pattern[DAY0] = tmp[0];
        pattern[DAY1] = tmp[1];

        assume_valid_invocation();

        if (result.tm_mday != i) {
            throw TestFailed{"Invalid day"};
        }
    }
}

void TestValidConversion::test_parse_hour() {

    for (int i=1; i <= 24; i++) {

        snprintf(tmp, sizeof(tmp), "%02d", i);
        result.tm_hour = -1;
        pattern = valid_pattern;
        pattern[HOUR0] = tmp[0];
        pattern[HOUR1] = tmp[1];

        assume_valid_invocation();

        if (result.tm_hour != i) {
            throw TestFailed{"Invalid hour"};
        }
    }
}

void TestValidConversion::test_parse_minute() {

    for (int i=0; i <= 59; i++) {

        snprintf(tmp, sizeof(tmp), "%02d", i);
        result.tm_min = -1;
        pattern = valid_pattern;
        pattern[MINUTE0] = tmp[0];
        pattern[MINUTE1] = tmp[1];

        assume_valid_invocation();

        if (result.tm_min != i) {
            throw TestFailed{"Invalid minute"};
        }
    }
}

void TestValidConversion::test_parse_second() {

    for (int i=0; i <= 59; i++) {

        snprintf(tmp, sizeof(tmp), "%02d", i);
        result.tm_sec = -1;
        pattern = valid_pattern;
        pattern[SECOND0] = tmp[0];
        pattern[SECOND1] = tmp[1];

        assume_valid_invocation();

        if (result.tm_sec != i) {
            throw TestFailed{"Invalid sec"};
        }
    }
}


class TestErrorDetection: public TestBase {

public:
    bool test_all();

private:
    void test_invalid_characters();
    void test_invalid_weekday_name();
    void test_invalid_month_name();
    void test_invalid_year();
    void test_invalid_day();
    void test_invalid_hour();
    void test_invalid_minute();
    void test_invalid_second();
};


bool TestErrorDetection::test_all() {
    try {
        test("Invalid characters",      std::bind(&TestErrorDetection::test_invalid_characters, this));
        test("Wrong name of weekday",   std::bind(&TestErrorDetection::test_invalid_weekday_name, this));
        test("Wrong name of month",     std::bind(&TestErrorDetection::test_invalid_month_name, this));
        test("Invalid year",            std::bind(&TestErrorDetection::test_invalid_year, this));
        test("Invalid day",             std::bind(&TestErrorDetection::test_invalid_day, this));
        test("Invalid hour",            std::bind(&TestErrorDetection::test_invalid_hour, this));
        test("Invalid minute",          std::bind(&TestErrorDetection::test_invalid_minute, this));
        test("Invalid second",          std::bind(&TestErrorDetection::test_invalid_second, this));
        return true;
    } catch (TestFailed& e) {
        puts(e.what());
        printf("pattern = '%s'\n", pattern.c_str());
        return false;
    }
}


void TestErrorDetection::test_invalid_characters() {
    const char* valid[] = {
        "SMTWTFS",
        "uouehra",
        "nneduit",
        ",",
        " ",
        "0123456789",
        "0123456789",
        " ",
        "JFMAMJJASOND",
        "aeapauuuecoe",
        "nbrrynlgptvc",
        " ",
        "0123456789",
        "0123456789",
        "0123456789",
        "0123456789",
        " ",
        "0123456789",
        "0123456789",
        ":",
        "0123456789",
        "0123456789",
        ":",
        "0123456789",
        "0123456789",
        " ",
        "G",
        "M",
        "T",
    };

    for (size_t i=0; i < valid_pattern.size(); i++) {
        pattern = valid_pattern;
        for (int b=0; b < 256; b++) {
            if (strchr(valid[i], b))
                continue;

            pattern[i] = b;
            assume_invalid_invocation();
        }
    }
}


void TestErrorDetection::test_invalid_weekday_name() {

    std::set<std::string> valid_names(weekdays, weekdays + 7);

    pattern = valid_pattern;
    for (int b0 = 0; b0 < 256; b0++) {
        pattern[WEEKDAY0] = b0;
        for (int b1 = 0; b1 < 256; b1++) {
            pattern[WEEKDAY1] = b1;
            for (int b2 = 0; b2 < 256; b2++) {
                pattern[WEEKDAY2] = b2;
                const auto ret = invocation();
                if (ret < 0)
                    continue;

                std::string tmp = pattern.substr(0, 3);
                if (valid_names.count(tmp) == 0) {
                    printf("b0, b1, b2 = {%02x, %02x, %02x}\n", b0, b1, b2);
                    throw TestFailed{"'" + tmp + "' is not a valid month name"};
                }
            }
        }
    }
}


void TestErrorDetection::test_invalid_month_name() {

    std::set<std::string> valid_names(months, months + 12);

    pattern = valid_pattern;
    for (int b0 = 0; b0 < 256; b0++) {
        pattern[MONTH0] = b0;
        for (int b1 = 0; b1 < 256; b1++) {
            pattern[MONTH1] = b1;
            for (int b2 = 0; b2 < 256; b2++) {
                pattern[MONTH2] = b2;
                const auto ret = invocation();
                if (ret < 0)
                    continue;

                std::string tmp = pattern.substr(8, 3);
                if (valid_names.count(tmp) == 0) {
                    printf("b0, b1, b2 = {%02x, %02x, %02x}\n", b0, b1, b2);
                    throw TestFailed{"'" + tmp + "' is not a valid month name"};
                }
            }
        }
    }
}


void TestErrorDetection::test_invalid_year() {

    pattern = valid_pattern;
    for (int x=0; x <= 9999; x++) {
        if (x >= 1900 && x <= 2900)
            continue;

        snprintf(tmp, sizeof(tmp), "%04d", x);

        pattern[YEAR0] = tmp[0];
        pattern[YEAR1] = tmp[1];
        pattern[YEAR2] = tmp[2];
        pattern[YEAR3] = tmp[3];

        assume_invalid_invocation();
    }
}

void TestErrorDetection::test_invalid_day() {

    pattern = valid_pattern;
    for (int x=0; x <= 99; x++) {
        if (x >= 1 && x <= 31)
            continue;

        snprintf(tmp, sizeof(tmp), "%02d", x);

        pattern[DAY0] = tmp[0];
        pattern[DAY1] = tmp[1];

        assume_invalid_invocation();
    }
}

void TestErrorDetection::test_invalid_hour() {

    pattern = valid_pattern;
    for (int x=0; x <= 99; x++) {
        if (x >= 1 && x <= 24)
            continue;

        snprintf(tmp, sizeof(tmp), "%02d", x);

        pattern[HOUR0] = tmp[0];
        pattern[HOUR1] = tmp[1];

        assume_invalid_invocation();
    }
}

void TestErrorDetection::test_invalid_minute() {

    pattern = valid_pattern;
    for (int x=0; x <= 99; x++) {
        if (x >= 0 && x <= 59)
            continue;

        snprintf(tmp, sizeof(tmp), "%02d", x);

        pattern[MINUTE0] = tmp[0];
        pattern[MINUTE1] = tmp[1];

        assume_invalid_invocation();
    }
}


void TestErrorDetection::test_invalid_second() {

    for (int x=0; x <= 99; x++) {
        if (x >= 0 && x <= 59)
            continue;

        snprintf(tmp, sizeof(tmp), "%02d", x);

        pattern[SECOND0] = tmp[0];
        pattern[SECOND1] = tmp[1];

        assume_invalid_invocation();
    }
}


int main() {
    TestValidConversion valid_conversion;
    TestErrorDetection  error_detection;

    const bool ret = valid_conversion.test_all() && error_detection.test_all();

    return ret ? EXIT_SUCCESS : EXIT_FAILURE;
}

