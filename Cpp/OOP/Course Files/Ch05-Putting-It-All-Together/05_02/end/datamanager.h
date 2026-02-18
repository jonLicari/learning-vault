#ifndef DATAMANAGER_H
#define DATAMANAGER_H

// data_manager.h
#include <string>

// Forward declarations
class IFileReader;
class IDataProcessor;
class IDBWrapper;
class ILogger;

class DataManager
{
public:
  DataManager(IFileReader *reader,
              IDataProcessor *processor,
              IDBWrapper *db,
              ILogger *logger);
  ~DataManager();

  // Prevent copying since we're managing raw pointers
  DataManager(const DataManager &) = delete;
  DataManager &operator=(const DataManager &) = delete;

  void processFile(const std::string &filename);

private:
  IFileReader *reader;
  IDataProcessor *processor;
  IDBWrapper *db;
  ILogger *logger;
};

#endif