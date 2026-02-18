#include "datahandler.h"

#include <fstream>
#include <ctime>

DataHandler::DataHandler()
    : rawData(), processedData()
{ // Initialize our vectors
  // Log the creation of the processor
  logOperation("DataHandler instance created");
}

void DataHandler::readFromFile(const std::string &filename)
{
  std::ifstream file(filename);
  if (!file)
  {
    throw std::runtime_error("Cannot open file: " + filename);
  }

  std::string line;
  while (std::getline(file, line))
  {
    rawData.push_back(line);
  }
  logOperation("File read: " + filename);
}

void DataHandler::processData()
{
  if (rawData.empty())
  {
    throw std::runtime_error("No data to process");
  }

  for (const auto &line : rawData)
  {
    processedData.push_back("Processed: " + line);
  }
  logOperation("Data processed");
}

void DataHandler::saveToDatabase()
{
  if (processedData.empty())
  {
    throw std::runtime_error("No processed data to save");
  }

  // Simulate DB operations
  std::ofstream db("database.txt", std::ios::app);
  for (const auto &data : processedData)
  {
    db << data << std::endl;
  }
  logOperation("Saved to database");
}

// Records operations for debugging and monitoring
void DataHandler::logOperation(const std::string &operation)
{
  std::cout << "LOG: " << operation << " at "
            << std::time(nullptr) << "\n";
  // In a real application, this might:
  // - Write to a log file
  // - Update operation statistics
  // - Send monitoring data
}