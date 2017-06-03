#pragma once
#include "list.hh"


//Tape
template <class, class>
struct Tape {};

template <int...K, char...V>
struct Tape<List<int, K...>, List<char, V...>>
{

};
//Tape_Get
template <int, class>
struct Tape_Get
{};

template <int V>
struct Tape_Get<V, Tape<List<int>, List<char>>>
{
  static const char value = '\0';
};

template <int F, int...K, char...V, char VF, int VK>
struct Tape_Get<F, Tape<List<int, VK, K...>, List<char, VF, V...>>>
{
  static const char value =
    Tape_Get<F, Tape<List<int, K...>, List<char, V...>>>::value;
};

template <int F, int...K, char...V, char VF>
struct Tape_Get<F, Tape<List<int, F, K...>, List<char, VF, V...>>>
{
  static const char value = VF;
};

//TODO :  this is not optimized at all : remplace when possible
//Tape_Add
template <int, char, class>
struct Tape_Add
{};
template <int K, char V, int...Ks, char...Vs>
struct Tape_Add<K, V, Tape<List<int, Ks...>, List<char, Vs...>>>
{
  typedef Tape<List<int, K, Ks...>, List<char, V, Vs...>> type;
};
