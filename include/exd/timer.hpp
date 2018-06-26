#ifndef __EXD_TIMER__
#define __EXD_TIMER__
#include <chrono>
#include <string>
#include <sstream>
namespace exd {
namespace timer {
namespace TimerImplement {
template <typename RealType = double>
class timer
{
 public:
  timer() { tic(); };
  void     tic() { time_start_ = std::chrono::system_clock::now(); };
  RealType toc() {
    std::chrono::duration<RealType> time_elapsed =
        std::chrono::system_clock::now() - time_start_;
    return time_elapsed.count();
  };
  RealType operator()() { return toc(); };
  std::string info() {
    std::ostringstream oss("Time elapsed ", std::ios_base::ate);
    oss << toc() << " s.";
    return oss.str();
  }

 private:
  std::chrono::time_point<std::chrono::system_clock> time_start_;
};
static timer<double> instance;
}  // namespace TimerImplement

static void tic() { TimerImplement::instance.tic(); };

static auto toc() { return TimerImplement::instance.toc(); };

static auto info() { return TimerImplement::instance.info(); };

template <typename RealType = double>
auto timer() {
  return TimerImplement::timer<RealType>();
};

}  // namespace timer
}  // namespace exd
#endif  // __EXD_TIMER__
