#include "uppercaseprocessor.h"

std::string UppercaseProcessor::transform(const std::string &input)
{
  std::string result = input;

  for (char &c : result)
  {
    c = std::toupper(c);
  }
  return result;
}