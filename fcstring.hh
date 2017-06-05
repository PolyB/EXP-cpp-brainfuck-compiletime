#pragma once
#include "map.hh"

template <int P, char ...C>
struct FCString;


template <int P, char...C>
struct FCString<P, 0, C...>
{
  typedef Map<List<int>, List<char>> type;
};

template <int P>
struct FCString<P>
{
  typedef Map<List<int>, List<char>> type;
};

template <int P, char A, char...C>
struct FCString<P, A, C...>
{
  typedef
    typename Map_Add<P, A, typename FCString<P + 1, C...>::type>::type type;
};
