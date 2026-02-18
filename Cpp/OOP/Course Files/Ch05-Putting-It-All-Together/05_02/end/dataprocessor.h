#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include "idataprocessor.h"
#include <iostream>
#include <vector>

class DataProcessor : public IDataProcessor
{
public:
  std::vector<std::string> processData(
      const std::vector<std::string> &data) override;
};

#endif