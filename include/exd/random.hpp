#ifndef __EXD_RANDOM__
#define __EXD_RANDOM__
#include <random>
#include <algorithm>
namespace exd {
namespace random {
namespace RandomImplement {
class RandomClass
{
 public:
  RandomClass() {
    std::random_device rd;
    seed(rd());
  };
  void seed(std::size_t value) { engine_.seed(value); };
  std::mt19937_64 engine_;
};
static RandomClass instance;
/* distribution */
template <class DistributionType>
class distribution
{
 public:
  distribution(DistributionType dist) : dist_(dist){};
  auto                          operator()() { return dist_(instance.engine_); }

 private:
  DistributionType dist_;
};
}  // namespace RandomImplement

static auto& engine = RandomImplement::instance.engine_;

static void seed(std::size_t value) { RandomImplement::instance.seed(value); };

/*return a random number in [0,1]*/
template <typename RealType = double>
RealType random() {
  return (RealType)engine() / engine.max();
};

/*return a random number in [a,b], numbers can be gened*/
template <typename RealType = double>
RealType random(RealType a, RealType b) {
  if (a > b) std::swap(a, b);
  return (b - a) * random() + a;
};

template <typename RealType = double>
RealType random(RealType b) {
  return b * random();
};

template <class DistributionType>
RandomImplement::distribution<DistributionType> distribution(
    DistributionType dist) {
  return RandomImplement::distribution<DistributionType>(dist);
};

/*return a random number in [a,b), numbers can be gened*/
template <typename IntType = int>
IntType randint(IntType a, IntType b) {
  if (a > b) std::swap(a, b);
  else if (a == b)
    b = a + 1;
  return engine() % (b - a) + a;
};

template <typename IntType = int>
IntType randint(IntType b) {
  return randint(0, b);
};

template <typename Iter>
void shuffle(Iter first, Iter last) {
  std::shuffle(first, last, engine);
};

template <typename Container>
void shuffle(Container& container) {
  shuffle(std::begin(container), std::end(container));
};

template <typename Container>
auto choice(Container& container) {
  return container[gen(container.size() - 1)];
};

}  // namespace random
}  // namespace exd
#endif  // __EXD_RANDOM__
