#include "list.hh"
#include "cstring.hh"
#include "interpreter.hh"
#include <iostream>

//this program should show a tilde
typedef typename CString<'+', '+', '[', '+', '+', '>', '+', '<', ']', '>', '-',
                         '.'>::asmap in;

typedef Make_Interpreter<in>::type interpreter;

static const std::string out = interpreter::res::out();

int main()
{
  std::cout << out;
}
