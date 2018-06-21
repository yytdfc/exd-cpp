#ifndef __EXD_RANGE__
#define __EXD_RANGE__

// inspired from https://www.cnblogs.com/qicosmos/p/3540435.html

#include <vector>
#include <sstream>

namespace exd {
namespace range {

namespace RangeImplement {
template <typename NumberType>
class RangeClass
{
  class Iterator
  {
   public:
    Iterator(std::size_t idx, RangeClass& instance)
        : idx_(idx), instance_(instance) {
      value_ = instance_.begin_ + idx_ * instance_.step_;
    }

    NumberType operator*() { return value_; }

    const Iterator* operator++() {
      value_ += instance_.step_;
      ++idx_;
      return this;
    }

    const Iterator* operator--() {
      value_ -= instance_.step_;
      --idx_;
      return this;
    }

    bool operator==(const Iterator& iter) { return idx_ == iter.idx_; }

    bool operator!=(const Iterator& iter) { return idx_ != iter.idx_; }

   private:
    NumberType  value_;
    std::size_t idx_;
    RangeClass& instance_;
  };

 public:
  RangeClass(NumberType begin, NumberType end, NumberType step = 1)
      : begin_(begin), step_(step) {
    if ((step == 0) || (step > 0 && begin_ >= end) ||
        (step < 0 && begin_ <= end)) {
      std::ostringstream err("error: exd::range::range", std::ios_base::ate);
      err << "(" << begin << ", " << end << ", " << step << ")";
      throw std::invalid_argument(err.str());
    }
    n_step_ = (end - begin_) / step_;
    if (begin_ + n_step_ * step_ != end) {
      n_step_++;
    }
  }

  Iterator begin() { return Iterator(0, *this); }

  Iterator end() { return Iterator(n_step_, *this); }

  const NumberType operator[](std::size_t i) const {
    return begin_ + i * step_;
  }

  std::size_t size() const { return n_step_; }

  std::vector<NumberType> to_vector() {
    std::vector<NumberType> vec(n_step_);
    for (size_t i = 0; i != n_step_; ++i)
      vec[i] = operator[](i);
    return vec;
  };

 private:
  NumberType begin_;
  NumberType step_;
  std::size_t n_step_;
};
}  // namespace RangeImplement

template <typename T, typename V>
auto range(T begin, T end, V stepsize) {
  return RangeImplement::RangeClass<decltype(begin + end + stepsize)>(
      begin, end, stepsize);
}

template <typename T>
RangeImplement::RangeClass<T> range(T begin, T end) {
  return RangeImplement::RangeClass<T>(begin, end, 1);
}

template <typename T>
RangeImplement::RangeClass<T> range(T end) {
  return RangeImplement::RangeClass<T>(T(), end, 1);
}
}  // namespace range
}  // namespace exd
#endif  // __EXD_RANGE__
