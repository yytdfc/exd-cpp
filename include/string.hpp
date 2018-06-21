#ifndef __EXD_STRING__
#define __EXD_STRING__
#include <string>
#include <vector>
namespace exd {
namespace string {
// using namespace std;
template <typename _CharT, typename _Traits, typename _Alloc>
std::vector<std::basic_string<_CharT, _Traits, _Alloc>> split(
    const std::basic_string<_CharT, _Traits, _Alloc>& str,
    const _CharT* delims = " \t\n",
    bool          reserve_empty = true) {
  typedef typename _Alloc::template rebind<_CharT>::other _CharT_alloc_type;
  typedef typename _CharT_alloc_type::size_type           size_type;
  std::vector<std::basic_string<_CharT, _Traits, _Alloc>> res;
  for (size_type init = 0;;) {
    auto pos = str.find_first_of(delims, init);
    if (pos == std::string::npos) {
      auto sub_str = str.substr(init, str.length());
      if (sub_str.empty()) {
        if (reserve_empty) res.emplace_back(sub_str);
      } else
        res.emplace_back(sub_str);
      break;
    }
    auto sub_str = str.substr(init, pos - init);
    if (sub_str.empty()) {
      if (reserve_empty) res.emplace_back(sub_str);
    } else
      res.emplace_back(sub_str);
    pos++;
    init = pos;
  }
  return res;
}
template <typename _CharT>
std::vector<std::basic_string<_CharT>> inline split(
    const _CharT* str,
    const _CharT* delims = " \t\n",
    bool          reserve_empty = true) {
  return split(std::basic_string<_CharT>(str), delims, reserve_empty);
}

template <typename _CharT, typename _Traits, typename _Alloc>
std::basic_string<_CharT, _Traits, _Alloc> strip(
    const std::basic_string<_CharT, _Traits, _Alloc>& str,
    const _CharT* trim = " \t") {
  auto first = str.find_first_not_of(trim);
  auto last = str.find_last_not_of(trim);
  return str.substr(first, last - first + 1);
}

template <typename _CharT>
std::basic_string<_CharT> inline strip(const _CharT* str,
                                       const _CharT* trim = " \n") {
  return strip(std::basic_string<_CharT>(str), trim);
}

template <typename _CharT, typename _Traits, typename _Alloc>
std::basic_string<_CharT, _Traits, _Alloc> join(
    const std::vector<std::basic_string<_CharT, _Traits, _Alloc>>& vec,
    const _CharT* sep = " ") {
  std::basic_string<_CharT, _Traits, _Alloc> res;
  for (auto& elem : vec)
    res.append(elem + sep);
  res.erase(--res.end());
  return res;
}
}
}
#endif  //__EXD_STRING__
