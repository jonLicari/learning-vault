#ifndef TEXTPROCESSOR_H
#define TEXTPROCESSOR_H

#include <string>

class TextProcessor
{
public:
  virtual ~TextProcessor() = default;

  // Core processing method
  std::string process(const std::string &input)
  {
    if (input.empty())
    {
      return input;
    }

    // Template method pattern
    std::string text = preProcess(input);
    text = transform(text);
    return postProcess(text);
  }

protected:
  // Hook methods that derived classes can override
  virtual std::string preProcess(const std::string &input)
  {
    return input; // Default: no pre-processing
  }

  // Pure virtual - must be implemented by derived classes
  virtual std::string transform(const std::string &input) = 0;

  virtual std::string postProcess(const std::string &input)
  {
    return input; // Default: no post-processing
  }
};

#endif