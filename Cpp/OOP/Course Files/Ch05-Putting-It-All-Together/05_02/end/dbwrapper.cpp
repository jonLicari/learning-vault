#include "dbwrapper.h"
#include <fstream>

void DBWrapper::saveData(const std::vector<std::string> &data)
{
  if (data.empty())
  {
    throw std::runtime_error("No data to save");
  }

  std::ofstream db("database.txt", std::ios::app);
  for (const auto &item : data)
  {
    db << item << "\n";
  }
}