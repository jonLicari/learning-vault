#include "dataprocessor.h"

#include <fstream>
#include <ctime>

std::vector<std::string> DataProcessor::processData(
    const std::vector<std::string> &data)
{
  if (data.empty())
  {
    throw std::runtime_error("No data to process");
  }

  std::vector<std::string> processed;
  for (const auto &line : data)
  {
    processed.push_back("Processed: " + line);
  }
  return processed;
}