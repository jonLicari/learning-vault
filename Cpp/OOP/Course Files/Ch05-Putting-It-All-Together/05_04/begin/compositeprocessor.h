#ifndef COMPOSITEPROCESSOR_H
#define COMPOSITEPROCESSOR_H

#include "textprocessor.h"
#include <vector>

class CompositeProcessor : public TextProcessor
{
public:
  ~CompositeProcessor()
  {
    for (auto *proc : processors)
    {
      delete proc; // Clean up each processor
    }
  }

  void addProcessor(TextProcessor *processor)
  {
    processors.push_back(processor);
  }

protected:
  std::string transform(const std::string &input) override
  {
    std::string result = input;
    for (auto *proc : processors)
    {
      result = proc->process(result);
    }
    return result;
  }

private:
  std::vector<TextProcessor *> processors;
};

#endif