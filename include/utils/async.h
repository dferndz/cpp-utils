#ifndef _async_h_
#define _async_h_


#include <thread>
#include <mutex>
#include <list>

#include "barrier.h"
#include "range.h"
#include "atomic.h"
#include "time.h"


template <typename T = void>
class async {
  T val;
  std::mutex mux;
  std::thread t;
  std::list<std::thread> callbacks;
public:
  template <typename W>
  async(W work) {
    mux.lock();
    t = std::thread([this, work] {
      val = work();
      mux.unlock();
    });
  }

  T get() {
    mux.lock();
    mux.unlock();
    return val;
  }

  template <typename W>
  void then(W work) {
    callbacks.push_back(std::thread([this, work] {
      mux.lock();
      mux.unlock();
      work(val);
    }));
  }

  virtual ~async() {
    try {
      t.join();
    } catch (std::exception &e) {}

    foreach(callbacks, [] (std::thread &th) {
      try {
        th.join();
      } catch (std::exception &e) {}
    });
  }
};

template<>
class async<void> {
  std::thread t;
public:
  template <typename W>
  async(W work) {
    t = std::thread(work);
  }

  virtual ~async() {
    try {
      t.join();
    } catch (std::exception &e) {}
  }

  template <typename R, typename P>
  static void sleepFor(std::chrono::duration<R, P> d) {
    std::this_thread::sleep_for(d);
  }

  static void yield() {
    std::this_thread::yield();
  }

  static std::thread::id stop() {
    return std::this_thread::get_id();
  }
};

#endif