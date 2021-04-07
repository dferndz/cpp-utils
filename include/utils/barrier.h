#ifndef _barrier_h_
#define _barrier_h_


#include <mutex>

#include "atomic.h"


class Barrier {
  Atomic<uint32_t> counter;
  std::mutex mux;
public:
  Barrier(uint32_t count): counter(count) {
    mux.lock();
  }
  void sync() {
    if(counter.add_fetch(-1) == 0) {
      mux.unlock();
    }

    mux.lock();
    mux.unlock();
  }

  static std::shared_ptr<Barrier> make(uint32_t count) {
    return std::make_shared<Barrier>(count);
  }
};

#endif