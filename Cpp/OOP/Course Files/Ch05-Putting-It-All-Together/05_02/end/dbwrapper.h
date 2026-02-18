#ifndef DBWRAPPER_H
#define DBWRAPPER_H

#include "idbwrapper.h"
#include <vector>

class DBWrapper : public IDBWrapper
{
public:
  void saveData(const std::vector<std::string> &data) override;
};

#endif