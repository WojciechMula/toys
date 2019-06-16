#include "regex.h"
#include <iostream>

int main() {

    nonstd::regex re(std::regex{"[A-Za-z]+"});

    if (re.match("foobar"))
        std::cout << "match!" << '\n';

    for (auto it: nonstd::regex(std::regex{"a=([0-9]+), b=([0-9]+)"}).iter("a=124, b=42"))
        std::cout << it << '\n';

    for (auto it: nonstd::regex(std::regex{"a=([0-9]+), b=([0-9]+)"}).iter("a=8090, c=2"))
        std::cout << it << '\n';
}
