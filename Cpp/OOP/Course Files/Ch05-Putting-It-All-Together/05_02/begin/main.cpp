#include "datahandler.h"
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

  // Run our demonstration
  DataHandler handler;

  // Try processing a file
  try
  {
    // First operation: read from file
    std::cout << "\nAttempting to read data..." << std::endl;
    handler.readFromFile("input.txt");

    // Second operation: process the data
    std::cout << "\nProcessing data..." << std::endl;
    handler.processData();

    // Third operation: save results
    std::cout << "\nSaving to database..." << std::endl;
    handler.saveToDatabase();

    std::cout << "\nAll operations completed successfully!" << std::endl;
  }
  catch (const std::exception &e)
  {
    std::cout << "\nError occurred: " << e.what() << std::endl;
  }

  return 0;
}