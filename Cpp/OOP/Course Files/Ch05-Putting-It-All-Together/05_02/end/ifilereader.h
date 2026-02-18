#ifndef IFILEREADER_H
#define IFILEREADER_H

#include <iostream>
#include <vector>

// Abstract IFileReader class
class IFileReader
{
public:
  virtual ~IFileReader() = default;
  virtual std::vector<std::string> readLines(const std::string &filename) = 0;
};

#endif