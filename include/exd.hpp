#include <string>
#include <vector>
#include <array>
#include <map>
#include <initializer_list>
#include <iostream>

namespace exd{
using namespace std;
template<typename _CharT, typename _Traits, typename _Alloc>
  std::vector<basic_string<_CharT, _Traits, _Alloc>>
  split(const basic_string<_CharT, _Traits, _Alloc>& str, const _CharT* delims=" \t") {
    typedef typename _Alloc::template rebind<_CharT>::other _CharT_alloc_type;
    typedef typename _CharT_alloc_type::size_type	    size_type;
    std::vector<basic_string<_CharT, _Traits, _Alloc>> res;
    for(size_type init=0;;) {
      auto pos = str.find_first_of(delims, init);
      if (pos == std::string::npos) {
        res.emplace_back(str.substr(init, str.length()));
        break;
      }
      res.emplace_back(str.substr(init, pos - init));
      pos++;
      init = pos;
    }
    return res;
  }
template<typename _CharT>
  std::vector<basic_string<_CharT>>
  inline split(const _CharT* str, const _CharT* delims = " \n"){
    return split(basic_string<_CharT>(str), delims);
  }

template<typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc>
  strip(const basic_string<_CharT, _Traits, _Alloc>& str, const _CharT* trim=" \t") {
    auto first=str.find_first_not_of(trim);
    auto last=str.find_last_not_of(trim);
    return str.substr(first, last-first+1);
  }

template<typename _CharT>
  basic_string<_CharT>
  inline strip(const _CharT* str, const _CharT* trim = " \n"){
    return strip(basic_string<_CharT>(str), trim);
  }

template<typename _CharT, typename _Traits, typename _Alloc>
  basic_string<_CharT, _Traits, _Alloc>
  join(const std::vector<basic_string<_CharT, _Traits, _Alloc>>& vec, const _CharT* sep =" ") {
    basic_string<_CharT, _Traits, _Alloc> res;
    for (auto elem = std::begin(vec); elem != std::end(vec) - 1; ++elem)
      res.append(*elem + sep);
    res.append(vec.back());
    return res;
  }

}

template<typename T>
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
template<typename T1, typename T2>
std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
  s.put('{');
  char comma[3] = {'\0', ' ', '\0'};
  for (const auto& p : m) {
    s << comma << p.first << ':' << p.second;
    comma[0] = ',';
  }
  return s << '}';
}
