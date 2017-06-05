#pragma once
#include "fcstring.hh"
#include <string>

template <char...S>
struct CString{
  static std::string out()
  {
    return std::string{S...};
  }

  typedef typename FCString<0, S...>::type asmap;
};
