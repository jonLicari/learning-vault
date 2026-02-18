#include "datamanager.h"
#include "filereader.h"
#include "dataprocessor.h"
#include "dbwrapper.h"
#include "logger.h"

#include <fstream>

int main()
{
  std::cout << "Data Processing Demo" << std::endl;
  std::cout << "===================" << std::endl;

  // Create a sample input file
  {
    std::ofstream input("input.txt");
    input << "First line of data" << std::endl;
    input << "Second line of data" << std::endl;
    input << "Third line of data" << std::endl;
  }

  // Create concrete implementations
  FileReader *reader = new FileReader();
  DataProcessor *processor = new DataProcessor();
  DBWrapper *dbWrapper = new DBWrapper();
  Logger *logger = new Logger();

  // Create manager with injected dependencies
  DataManager manager(reader, processor, dbWrapper, logger);

  // Try processing a file
  try
  {
    // Process the file
    manager.processFile("input.txt");

    std::cout << "\nAll operations completed successfully!" << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << "\nError occurred: " << e.what() << std::endl;
  }

  return 0;
}