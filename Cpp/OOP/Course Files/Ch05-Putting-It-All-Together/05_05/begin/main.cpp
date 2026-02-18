#include "whitespaceprocessor.h"
#include "uppercaseprocessor.h"
#include "compositeprocessor.h"
#include <iostream>

int main()
{
  std::string text = "  Hello,   World!  \n";
  std::cout << "Original text: '" << text << "'\n";

  CompositeProcessor composite;
  composite.addProcessor(new WhitespaceProcessor()); // First, clean up spacing
  composite.addProcessor(new UppercaseProcessor());  // Then convert to uppercase

  std::cout << "After composite processing: '"
            << composite.process(text) << "'\n";
}