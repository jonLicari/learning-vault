#ifndef WHITESPACEPROCESSOR_H
#define WHITESPACEPROCESSOR_H

#include "textprocessor.h"

class WhitespaceProcessor : public TextProcessor
{
protected:
  std::string preProcess(const std::string &input) override;
  std::string transform(const std::string &input) override;
  std::string postProcess(const std::string &input) override;
};

#endif