#pragma once

template <bool, class A, A B, A C>
struct If;

template <class A, A B, A C>
struct If<true, A, B, C>
{
  static const A value = B;
};

template <class A, A B, A C>
struct If<false, A, B, C>
{
  static const A value = C;
};
