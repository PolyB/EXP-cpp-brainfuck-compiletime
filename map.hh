#pragma once
#include "list.hh"


//Map
template <class, class>
struct Map;

template <int...K, char...V>
struct Map<List<int, K...>, List<char, V...>>
{
};
//Map_Get
template <int, class>
struct Map_Get;

template <int V>
struct Map_Get<V, Map<List<int>, List<char>>>
{
  static const char value = '\0';
};

template <int F, int...K, char...V, char VF, int VK>
struct Map_Get<F, Map<List<int, VK, K...>, List<char, VF, V...>>>
{
  static const char value =
    Map_Get<F, Map<List<int, K...>, List<char, V...>>>::value;
};

template <int F, int...K, char...V, char VF>
struct Map_Get<F, Map<List<int, F, K...>, List<char, VF, V...>>>
{
  static const char value = VF;
};

//TODO :  this is not optimized at all : remplace when possible
//Map_Add
template <int, char, class>
struct Map_Add;

template <int K, char V, int...Ks, char...Vs>
struct Map_Add<K, V, Map<List<int, Ks...>, List<char, Vs...>>>
{
  typedef Map<List<int, K, Ks...>, List<char, V, Vs...>> type;
};
