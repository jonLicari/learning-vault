#ifndef UPPERCASEPROCESSOR_H
#define UPPERCASEPROCESSOR_H

#include "textprocessor.h"

class UppercaseProcessor : public TextProcessor
{
protected:
  std::string transform(const std::string &input) override;
};

#endif