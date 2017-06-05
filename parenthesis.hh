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
  static const int value = Pos;
};

template <int Pos, int C, int... A, char... B>
struct Parenthesis_O_Get_E<'\0', C, Pos,
                           Map<List<int, A...>, List<char, B...>>>
{

};


template <char, class, int, int, class>
struct Parenthesis_O_Get_S;

template<char Char, int...Op, int Pos, int...A, char...B, int R>
struct Parenthesis_O_Get_S<Char, List<int, Op...>, Pos, R, Map<List<int, A...>,
                           List<char, B...>>>
{
  static const int value = Parenthesis_O_Get_S<
    Map_Get<Pos + 1, Map<List<int, A...>, List<char, B...>>>::value,
    List<int, Op...>,
    Pos + 1,
    R,
    Map<List<int, A...>, List<char, B...>>>::value;
};

template<int...Op, int...A, int Pos, char...B, int R>
struct Parenthesis_O_Get_S<'[', List<int, Op...>, Pos, R, Map<List<int, A...>,
                           List<char, B...>>>
{
  static const int value = Parenthesis_O_Get_S<
    Map_Get<Pos + 1, Map<List<int, A...>, List<char, B...>>>::value,
    List<int, Pos, Op...>,
    Pos + 1,
    R,
    Map<List<int, A...>, List<char, B...>>>::value;
};

template <int... Op, int Co, int... A, int Pos, char... B, int R>
struct Parenthesis_O_Get_S<']', List<int, Co, Op...>, Pos, R,
                           Map<List<int, A...>, List<char, B...>>>
{
  static const int value = Parenthesis_O_Get_S<
    Map_Get<Pos + 1, Map<List<int, A...>, List<char, B...>>>::value,
    List<int, Op...>,
    Pos + 1,
    R,
    Map<List<int, A...>, List<char, B...>>>::value;
};

template <int ...Op, int Pos, int... A, char... B, int F>
struct Parenthesis_O_Get_S<']', List<int, F, Op...>, Pos, Pos,
                           Map<List<int, A...>, List<char, B...>>>
{
  static const int value = F;
};


template <char, int, class>
struct Parenthesis_Get_H;

template <int P, class C>
struct Parenthesis_Get_H<'[', P, C>
{
  static const int value = Parenthesis_O_Get_E<
    ' ',
    0,
    P,
    C>::value;
};
template <int P, class C>
struct Parenthesis_Get_H<']', P, C>
{
  static const int value = Parenthesis_O_Get_S<
    ' ',
    List<int>,
    -1,
    P,
    C>::value;
};

template <int Pos, class C>
struct Parenthesis_Get
{
  static const int value =
    Parenthesis_Get_H<Map_Get<Pos, C>::value, Pos, C>::value;
};
