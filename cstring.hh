#pragma once
#include "fcstring.hh"
#include <string>

template <char...S>
struct CString{
  static std::string asString()
  {
    return std::string{S...};
  }

  typedef typename FCString<0, S...>::type asmap;

};

template <char, class>
struct CStringPrepend;

template <char C, char...S>
struct CStringPrepend<C, CString<S...>>{
  typedef CString<C, S...> type;
};

template<int P, const char* R>
struct CStringConstChar;

template <int P, char C, const char* R>
struct CStringConstCharH
{
  typedef
    typename CStringPrepend<C, typename CStringConstChar<P, R>::type>::type
      type;
};

template <int P, const char* R>
struct CStringConstCharH<P, 0, R>
{
  typedef CString<>  type;
};

template<int P, const char* R>
struct CStringConstChar
{
  typedef typename CStringConstCharH<P + 1, R[P], R>::type type;
};
