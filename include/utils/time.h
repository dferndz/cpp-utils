#ifndef _time_h_
#define _time_h_

#include <chrono>

using namespace std::chrono_literals;

class Stopwatch {
  typedef std::chrono::time_point<std::chrono::high_resolution_clock> time_point_t;
  typedef std::chrono::high_resolution_clock hr_clock_t;

  bool isRunning;
  time_point_t startTime;
  time_point_t stopTime;
public:
  Stopwatch(): isRunning(false) {}
  void start() {
    isRunning = true;
    startTime = hr_clock_t::now();
  }

  void stop() {
    stopTime = hr_clock_t::now();
    isRunning = false;
  }

  double ellapsedMilliseconds() {
    if(isRunning) {
      return std::chrono::duration_cast<std::chrono::milliseconds>(hr_clock_t::now() - startTime).count();
    }
    return std::chrono::duration_cast<std::chrono::milliseconds>(stopTime - startTime).count();
  }

  template <typename W>
  static double measurePerformance(W work) {
    Stopwatch sw;

    sw.start();
    work();
    sw.stop();

    return sw.ellapsedMilliseconds();
  }
};

#endif