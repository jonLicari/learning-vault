#ifndef COMPOSITEPROCESSOR_H
#define COMPOSITEPROCESSOR_H

#include "textprocessor.h"
#include <vector>
#include <memory>

class CompositeProcessor : public TextProcessor
{
public:
  void addProcessor(std::unique_ptr<TextProcessor> processor)
  {
    processors.push_back(std::move(processor));
  }

protected:
  std::string transform(const std::string &input) override
  {
    std::string result = input;
    for (const auto &proc : processors)
    {
      result = proc->process(result);
    }
    return result;
  }

private:
  std::vector<std::unique_ptr<TextProcessor>> processors;
};

#endif