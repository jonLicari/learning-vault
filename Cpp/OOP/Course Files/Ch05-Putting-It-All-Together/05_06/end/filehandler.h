#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <iostream>

class FileHandler
{
public:
  FileHandler(const std::string &filename)
  {
    file = fopen(filename.c_str(), "r");
    if (!file)
    {
      throw std::runtime_error("Could not open file");
    }
  }

  ~FileHandler()
  {
    if (file)
    {
      fclose(file); // Automatically called when object is destroyed
    }
  }

  // Prevent copying to ensure single ownership
  FileHandler(const FileHandler &) = delete;
  FileHandler &operator=(const FileHandler &) = delete;

  FILE *get() { return file; }

private:
  FILE *file;
};

#endif