#ifndef FILEREADER_H
#define FILEREADER_H

#include "ifilereader.h"
#include <iostream>
#include <vector>

class FileReader : public IFileReader
{
public:
  // Returns the contents of the file as a vector of strings
  std::vector<std::string> readLines(const std::string &filename) override;
};

#endif