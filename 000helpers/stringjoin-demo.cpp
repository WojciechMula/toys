#include "stringjoin.h"

#include <cstdio>

int main() {

  printf("'%s'\n", stringjoin("_").c_str());
  printf("'%s'\n", stringjoin("_", "a").c_str());
  printf("'%s'\n", stringjoin("_", "a", "b").c_str());
  printf("'%s'\n", stringjoin("_", "a", "b", "c").c_str());
  printf("'%s'\n", stringjoin("_", "a", "b", "c", "d").c_str());
}
