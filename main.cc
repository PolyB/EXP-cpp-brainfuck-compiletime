#include "brainfuck.hh"
#include <iostream>

//this program should show a tilde

//typedef CString<'+', '+', '[', '+', '+', '>', '+', '<', ']', '>', '-', '.'>in;
//static const std::string out = Brainfuck<in>::result::asString();

extern constexpr const char in[] = "++[++>+<]>-.";
static const std::string out = Brainfuck<ConstChar<in>>::result::asString();

int main()
{
  std::cout << out;
}
