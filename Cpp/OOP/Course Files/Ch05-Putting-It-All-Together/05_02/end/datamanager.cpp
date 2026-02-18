#include "datamanager.h"
#include "ifilereader.h"
#include "idataprocessor.h"
#include "idbwrapper.h"
#include "ilogger.h"

DataManager::DataManager(IFileReader *reader,
                         IDataProcessor *processor,
                         IDBWrapper *db,
                         ILogger *logger)
    : reader(reader), processor(processor), db(db), logger(logger)
{
}

DataManager::~DataManager()
{
  delete reader;
  delete processor;
  delete db;
  delete logger;
}

void DataManager::processFile(const std::string &filename)
{
  try
  {
    logger->log("Starting file processing");

    auto rawData = reader->readLines(filename);
    logger->log("File read complete");

    auto processedData = processor->processData(rawData);
    logger->log("Processing complete");

    db->saveData(processedData);
    logger->log("Data saved to database");
  }
  catch (const std::exception &e)
  {
    logger->log(std::string("Error: ") + e.what());
    throw; // Re-throw for the caller
  }
}