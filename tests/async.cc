#include <utils/async.h>
#include <utils/tests.h>
#include <utils/range.h>

#define ARRAY_SIZE 10

uint32_t factorial(uint32_t n) {
  if (n < 2) return 1;
  return async<uint32_t>([n] {
    return factorial(n-1);
  }).get() * n;
}

int main(int argc, char *argv[]) {
  uint32_t expected[ARRAY_SIZE];

  expected[0] = 1;
  
  for(auto n : range(1, ARRAY_SIZE)) {
    expected[n] = n * expected[n-1];
  }

  for(auto n : range(0, ARRAY_SIZE)) {
    CHECK(expected[n] == factorial(n));
  }

  bool ready = false;

  auto p = async<int>([&ready] {
    using namespace std::chrono_literals;

    async<>::sleepFor(500ms);
    ready = true;
    return 10;
  });

  p.then([] (int n){
    CHECK(n == 10);
  });

  CHECK(p.get() == 10);
  CHECK(ready);

  TEST_END(argv);
}