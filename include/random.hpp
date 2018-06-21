#ifndef __EXD_RANDOM__
#define __EXD_RANDOM__
#include <random>
namespace exd {
namespace random {
namespace RandomImplement {
class RandomClass
{
 public:
  RandomClass() {
    std::random_device rd;
    engine_.seed(rd());
  };
  std::mt19937_64 engine_;
};
static RandomClass instance;
}  // namespace RandomImplement

static auto& engine = RandomImplement::instance.engine_;

/*return a random number in [0,1]*/
template <typename RealType = double>
RealType random() {
  return (RealType)engine() / engine.max();
};

template <typename RealType = double>
RealType random(RealType b) {
  return b * random();
};

/*return a random number in [a,b], numbers can be gened*/
template <typename RealType = double>
RealType random(RealType a, RealType b) {
  if (a > b) std::swap(a, b);
  return (b - a) * random() + a;
};

/*return a random number in [a,b), numbers can be gened*/
template <typename IntType = int>
IntType randint(IntType a, IntType b) {
  if (a == b) b = a + 1;
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
