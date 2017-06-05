#pragma once
#include "list.hh"
#include "map.hh"

template<char, int, int, class>
struct Parenthesis_O_Get_E;

template <char Prev, int Count, int Pos, int... A, char... B>
struct Parenthesis_O_Get_E<Prev, Count, Pos,
                           Map<List<int, A...>, List<char, B...>>>
{
  static const int value = Parenthesis_O_Get_E<
    Map_Get<Pos + 1, Map<List<int, A...>, List<char, B...>>>::value, Count,
    Pos + 1, Map<List<int, A...>, List<char, B...>>>::value;
};

template <int Count, int Pos, int... A, char... B>
struct Parenthesis_O_Get_E<'[', Count, Pos,
                           Map<List<int, A...>, List<char, B...>>>
{
  static const int value = Parenthesis_O_Get_E<
    Map_Get<Pos + 1, Map<List<int, A...>, List<char, B...>>>::value, Count + 1,
    Pos + 1, Map<List<int, A...>, List<char, B...>>>::value;
};

template <int Count, int Pos, int... A, char... B>
struct Parenthesis_O_Get_E<']', Count, Pos,
                           Map<List<int, A...>, List<char, B...>>>
{
  static const int value = Parenthesis_O_Get_E<
    Map_Get<Pos + 1, Map<List<int, A...>, List<char, B...>>>::value, Count - 1,
    Pos + 1, Map<List<int, A...>, List<char, B...>>>::value;
};

template <int Pos, int... A, char... B>
struct Parenthesis_O_Get_E<']', 0, Pos,
                           Map<List<int, A...>, List<char, B...>>>
{
  static const int  value = Pos;
};


template <int, class>
struct Parenthesis_O_Get;

template <int A, int...B, char...C>
struct Parenthesis_O_Get<A, Map<List<int, B...>, List<char, C...>>>
{

};
