#ifndef DATAPROCESSOR_H
#define DATAPROCESSOR_H

#include <iostream>
#include <vector>

class DataHandler
{
public:
  DataHandler();

  // Main operations
  void readFromFile(const std::string &filename);
  void processData();
  void saveToDatabase();

private:
  void logOperation(const std::string &operation);

  // Data storage
  std::vector<std::string> rawData;
  std::vector<std::string> processedData;
};

#endif