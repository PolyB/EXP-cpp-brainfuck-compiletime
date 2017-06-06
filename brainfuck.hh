#pragma once
#include "interpreter.hh"
#include "cstring.hh"

template <class>
struct Brainfuck;

template<char...C>
struct Brainfuck<CString<C...>>
{
  typedef
    typename Make_Interpreter<typename CString<C...>::asmap>::type::res result;
};

template <const char*D>
struct ConstChar;

template <const char*D>
struct Brainfuck<ConstChar<D>>
{
  typedef typename Make_Interpreter<
    typename CStringConstChar<0, D>::type::asmap>::type::res result;
};
