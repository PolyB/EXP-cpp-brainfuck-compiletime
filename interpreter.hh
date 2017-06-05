#pragma once
#include "map.hh"
#include "parenthesis.hh"
#include "cstring.hh"
#include "if.hh"

template <char, class>
struct IntNextInstr;

//Pos, Ptr, Program, Tape, loopsStack Output
template<int, int, class, class, class>
struct Interpreter{};

template <class C>
struct Make_Interpreter
{
  typedef Interpreter<0, 0, C, Map<List<int>, List<char>>, List<char>> type;
};

template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>
struct Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
                   Map<List<int, TapeK...>, List<char, TapeV...>>,
                   List<char, Out...>>
{

  typedef typename IntNextInstr<
    Map_Get<Pos, Map<List<int, ProgK...>, List<char, ProgV...>>>::value,
    Interpreter<
    Pos,
    Ptr,
    Map<List<int, ProgK...>, List<char, ProgV...>>,
    Map<List<int, TapeK...>, List<char, TapeV...>>,
    List<char, Out...>>>::type res;
};




//IntNextInstr

template <char Instr, int Pos, int Ptr, int... ProgK, char... ProgV,
          int... TapeK, char... TapeV, char... Out>

  struct IntNextInstr < Instr,
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{

};

// >
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>

  struct IntNextInstr < '>',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{
  typedef typename Interpreter<Pos + 1, Ptr + 1,
                      Map<List<int, ProgK...>, List<char, ProgV...>>,
                      Map<List<int, TapeK...>, List<char, TapeV...>>,
                      List<char, Out...>>::res
    type;
};

// [
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>

  struct IntNextInstr < '[',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{
  typedef typename Interpreter<
    If<Map_Get<Ptr, Map<List<int, TapeK...>, List<char, TapeV...>>>::value ==
         '\0',
       int, Parenthesis_Get<
               Pos, Map<List<int, ProgK...>, List<char, ProgV...>>>::value +
             1,
       Pos + 1>::value,
    Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
    Map<List<int, TapeK...>, List<char, TapeV...>>, List<char, Out...>>::res
    type;
};

// ]
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>

  struct IntNextInstr < ']',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{
  typedef typename Interpreter<
    If<Map_Get<Ptr, Map<List<int, TapeK...>, List<char, TapeV...>>>::value !=
         '\0',
       int,
       Parenthesis_Get<Pos,
                       Map<List<int, ProgK...>, List<char, ProgV...>>>::value +
         1,
       Pos + 1>::value,
    Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
    Map<List<int, TapeK...>, List<char, TapeV...>>, List<char, Out...>>::res
    type;
};

// .
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>

  struct IntNextInstr < '.',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{
  typedef typename Interpreter<
    Pos + 1, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
    Map<List<int, TapeK...>, List<char, TapeV...>>,
    List<char,
         Map_Get<Ptr, Map<List<int, TapeK...>, List<char, TapeV...>>>::value,
         Out...>>::res
    type;
};

// +


template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>

  struct IntNextInstr < '+',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{
  typedef typename Interpreter<
    Pos + 1, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
      typename Map_Add<
        Ptr,
        1 + Map_Get<Ptr, Map<List<int, TapeK...>, List<char, TapeV...>>>::value,
        Map<List<int, TapeK...>, List<char, TapeV...>>>::type,
      List<char, Out...>>::res type;
};

// -


template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>

  struct IntNextInstr < '-',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{
  typedef typename Interpreter<
    Pos + 1, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
      typename Map_Add<
        Ptr,
        Map_Get<Ptr, Map<List<int, TapeK...>, List<char, TapeV...>>>::value - 1,
        Map<List<int, TapeK...>, List<char, TapeV...>>>::type,
      List<char, Out...>>::res type;
};

// End
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, char... Out>

  struct IntNextInstr < '\0',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<char, Out...>>>
{
  typedef CString<Out...> type;
};
