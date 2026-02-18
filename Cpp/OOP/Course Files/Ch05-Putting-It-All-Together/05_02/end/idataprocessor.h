#ifndef IDATAPROCESSOR_H
#define IDATAPROCESSOR_H

#include <iostream>
#include <vector>

// Abstract IDataProcessor class
class IDataProcessor
{
public:
  virtual ~IDataProcessor() = default;
  virtual std::vector<std::string> processData(
      const std::vector<std::string> &data) = 0;
};

#endif