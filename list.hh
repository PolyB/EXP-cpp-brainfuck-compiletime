#pragma once
template <typename A, A... V>
struct List
{
};

template <typename A>
struct List<A>
{
  static const bool empty = true;
  typedef List<A> rest;
};

template <typename A, A F, A...V>
struct List<A, F, V...>
{
  static const bool empty = false;
  static const A first = F;
  typedef List<A, V...> rest;
};
