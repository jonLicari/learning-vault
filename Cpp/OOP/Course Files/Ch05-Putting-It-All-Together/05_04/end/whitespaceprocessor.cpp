#include "whitespaceprocessor.h"

std::string WhitespaceProcessor::preProcess(const std::string &input)
{
  // Trim leading whitespace
  std::string result = input;
  result.erase(0, result.find_first_not_of(" \t\n"));
  return result;
}

std::string WhitespaceProcessor::transform(const std::string &input)
{
  // Replace multiple spaces with single space
  std::string result;
  bool lastWasSpace = false;

  for (char c : input)
  {
    if (std::isspace(c))
    {
      if (!lastWasSpace)
      {
        result += ' ';
        lastWasSpace = true;
      }
    }
    else
    {
      result += c;
      lastWasSpace = false;
    }
  }
  return result;
}

std::string WhitespaceProcessor::postProcess(const std::string &input)
{
  // Trim trailing whitespace
  std::string result = input;
  result.erase(result.find_last_not_of(" \t\n") + 1);
  return result;
}
