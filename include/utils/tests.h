#ifndef _tests_h_
#define _tests_h_

#include <iostream>

class Tests {
  static uint32_t correct;
  static uint32_t incorrect;
public:

  static void testCorrect() {
    correct++;
  }

  static void testIncorrect() {
    incorrect++;
  }

  static uint32_t getIncorrect() {
    return incorrect;
  }

  static uint32_t getCorrect() {
    return correct;
  }

  static uint32_t getTotal() {
    return correct + incorrect;
  }

  static void printSummary(char* argv[]) {
    if(argv) {
      std::cout << argv[0] << " ";
    }

    std::cout << " --- " << (getIncorrect() == 0 ? "PASS" : "FAIL") << " [" << getCorrect() << "/" << getTotal() << "]"<< std::endl;
  }
};

uint32_t Tests::correct = 0;
uint32_t Tests::incorrect = 0;

#define CHECK(expr) if((!(expr))) {\
  std::cerr << "Check failed [" << #expr << "] at " << __FILE__ << ":" << __LINE__ << std::endl;\
  Tests::testIncorrect();\
} else {\
  Tests::testCorrect();\
}

#define TEST_END(argv) \
  Tests::printSummary(argv);\
  if(Tests::getIncorrect() > 0) return 1;\
  return 0;

#endif