#include "filereader.h"
#include <fstream>

std::vector<std::string> FileReader::readLines(const std::string &filename)
{
  std::vector<std::string> lines;
  std::ifstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Cannot open file: " + filename);
  }

  std::string line;
  while (std::getline(file, line))
  {
    lines.push_back(line);
  }
  return lines;
}