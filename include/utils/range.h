#ifndef _utils_h_
#define _utils_h_

#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#include <random>
#include <iostream>

class range_itr {
protected:
  int val;
public:
  range_itr(const range_itr& itr): val(itr.val) {}
  range_itr(int val): val(val) {}
  virtual bool operator!=(range_itr& itr) {
    return val != itr.val;
  }
  virtual void operator++() {
    val++;
  }
  virtual int& operator*() {
    return val;
  }
};

template <unsigned max = INT_MAX, unsigned min = 0>
class random_itr: public range_itr {
  int rand_val;
public:
  random_itr(int val): range_itr(val) {}
  int& operator*() override {
    rand_val = (std::rand() % (max - min)) + min;
    return rand_val;
  }
};

template <typename itr_t = range_itr>
class range {
protected:
  int start, finish;
public:
  range(int finish): start(0), finish(finish) {}
  range(int start, int finish): start(start), finish(finish) {}
  itr_t begin() {
    return itr_t{start};
  }
  itr_t end() {
    return itr_t{finish};
  }
};

template <typename list_t, typename func_t>
void foreach(list_t &list, func_t func) {
  for(auto &n : list)
    func(n);
}

template <typename list_t, typename func_t>
void foreach(list_t &&list, func_t func) {
  for(auto n : list)
    func(n);
}

template <typename list_t, typename func_t, typename after_t>
void foreach(list_t &list, func_t func, after_t after) {
  for(auto &n : list)
    func(n);
  after();
}

template <typename list_t, typename func_t, typename after_t>
void foreach(list_t &&list, func_t func, after_t after) {
  for(auto n : list)
    func(n);
  after();
}

namespace helpers {
  template <typename T, char end_char = '\n'>
  void print(T val) {
    std::cout << val << end_char;
  }
  void endl() {
    std::cout << std::endl;
  }
};

template <typename list_t>
list_t rand_list(size_t size, const unsigned max, const unsigned min = 0) {
  list_t the_list;

  for(auto n : range(size))
    the_list.push_back((std::rand() % (max - min)) + min);
  
  return the_list;
}

#endif