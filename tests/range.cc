#include <iostream>
#include <vector>
#include <string>

#include "utils/range.h"
#include "utils/tests.h"

#define TEST_LOOPS 5000

int main(int argc, char *argv[]) {
  for (uint32_t i = 0; i < TEST_LOOPS; i++) {
    uint32_t count = 0;
    for(auto n : range(i)) {
      count++;
    }
    CHECK(count == i);
  }

  uint32_t count = 1000;
  for(auto n : range(1000, TEST_LOOPS)) {
    CHECK(count == n);
    count++;
  }
  CHECK(count == TEST_LOOPS);


  TEST_END(argv);
}