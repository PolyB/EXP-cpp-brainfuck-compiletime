#pragma once
#include "map.hh"
#include <string>
#include <iostream>

template <char, class>
struct IntNextInstr;

//Pos, Ptr, Program, Tape, loopsStack Output
template<int, int, class, class, class, class>
struct Interpreter{};


template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, int... Loops, char...Out>
struct Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
                   Map<List<int, TapeK...>, List<char, TapeV...>>,
                   List<int, Loops...>, List<char, Out...>>
{
  //TODO : remplace
  static std::string out()
  {
    return std::string{Out...};
  }

  typedef typename IntNextInstr<
    Map_Get<Pos, Map<List<int, ProgK...>, List<char, ProgV...>>>::value,
    Interpreter<
    Pos + 1,
    Ptr,
    Map<List<int, ProgK...>, List<char, ProgV...>>,
    Map<List<int, TapeK...>, List<char, TapeV...>>,
    List<int, Loops...>, List<char, Out...>>>::type next;
};




//IntNextInstr

template <char Instr, int Pos, int Ptr, int... ProgK, char... ProgV,
          int... TapeK, char... TapeV, int... Loops, char... Out>

  struct IntNextInstr < Instr,
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<int, Loops...>, List<char, Out...>>>
{

};

// >
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, int... Loops, char... Out>

  struct IntNextInstr < '>',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<int, Loops...>, List<char, Out...>>>
{
  typedef typename Interpreter<Pos, Ptr + 1,
                      Map<List<int, ProgK...>, List<char, ProgV...>>,
                      Map<List<int, TapeK...>, List<char, TapeV...>>,
                      List<int, Loops...>, List<char, Out...>>::next
    type;
};
// [
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, int... Loops, char... Out>

  struct IntNextInstr < '[',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<int, Loops...>, List<char, Out...>>>
{
  typedef typename Interpreter<Pos, Ptr,
                      Map<List<int, ProgK...>, List<char, ProgV...>>,
                      Map<List<int, TapeK...>, List<char, TapeV...>>,
                      List<int, Pos, Loops...>, List<char, Out...>>::next
    type;
};

// .
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, int... Loops, char... Out>

  struct IntNextInstr < '.',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<int, Loops...>, List<char, Out...>>>
{
  typedef typename Interpreter<
    Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
    Map<List<int, TapeK...>, List<char, TapeV...>>, List<int, Loops...>,
    List<char,
         Map_Get<Ptr, Map<List<int, TapeK...>, List<char, TapeV...>>>::value,
         Out...>>::next
    type;
};

// +


template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, int... Loops, char... Out>

  struct IntNextInstr < '+',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<int, Loops...>, List<char, Out...>>>
{
  typedef typename Interpreter<
    Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
      typename Map_Add<
        Ptr,
        1 + Map_Get<Ptr, Map<List<int, TapeK...>, List<char, TapeV...>>>::value,
        Map<List<int, TapeK...>, List<char, TapeV...>>>::type,
      List<int, Loops...>, List<char, Out...>>::next type;
};

// End
template <int Pos, int Ptr, int... ProgK, char... ProgV, int... TapeK,
          char... TapeV, int... Loops, char... Out>

  struct IntNextInstr < '\0',
  Interpreter<Pos, Ptr, Map<List<int, ProgK...>, List<char, ProgV...>>,
              Map<List<int, TapeK...>, List<char, TapeV...>>,
              List<int, Loops...>, List<char, Out...>>>
{
  typedef Interpreter<Pos, Ptr,
                      Map<List<int, ProgK...>, List<char, ProgV...>>,
                      Map<List<int, TapeK...>, List<char, TapeV...>>,
                      List<int, Loops...>, List<char, Out...>>
    type;
};
