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
}

static auto& engine = RandomImplement::instance.engine_;

/*return a random number in [0,1]*/
template <typename RealType = double>
RealType random() {
  return (RealType)engine() / engine.max();
};

/*return a random number in [a,b], numbers can be gened*/
template <typename RealType = double>
RealType random(RealType a, RealType b) {
  assert(a <= b);
  return (b - a) * engine() / engine.max() + a;
};

template <typename IntType = int>
IntType randint(IntType a, IntType b) {
  assert(a < b);
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
}

}  // namespace exd
#endif  // __EXD_RANDOM_HPP_
