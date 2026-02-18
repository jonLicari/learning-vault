#include "whitespaceprocessor.h"
#include "uppercaseprocessor.h"
#include "compositeprocessor.h"
#include <iostream>

int main()
{
  std::string text = "  Hello,   World!  \n";
  std::cout << "Original text: '" << text << "'\n";

  // Use individual processors
  UppercaseProcessor up;
  std::cout << "After uppercase processing: '"
            << up.process(text) << "'\n";

  WhitespaceProcessor wp;
  std::cout << "After whitespace processing: '"
            << wp.process(text) << "'\n";
}