#ifndef __EXD_IO__
#define __EXD_IO__
#include <iostream>
#include <map>
#include <vector>
#include <array>
template <typename T>
std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
  s.put('[');
  char comma[3] = {'\0', ' ', '\0'};
  for (const auto& e : v) {
    s << comma << e;
    comma[0] = ',';
  }
  return s << ']';
}

template <typename T, size_t N>
std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
  s.put('[');
  char comma[3] = {'\0', ' ', '\0'};
  for (const auto& e : a) {
    s << comma << e;
    comma[0] = ',';
  }
  return s << ']';
}

template <typename T1, typename T2>
std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
  s.put('{');
  char comma[3] = {'\0', ' ', '\0'};
  for (const auto& p : m) {
    s << comma << p.first << ':' << p.second;
    comma[0] = ',';
  }
  return s << '}';
}
#endif  //__EXD_IO__
