#include <string>
#include <vector>
#include <initializer_list>
namespace exd{
using namespace std;
// using string = std::string;
// using basic_string = std::__cxx11::basic_string;
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
    for (auto& elem : vec) res.append(elem + sep);
    res.erase(--res.end());
    return res;
  }

}
