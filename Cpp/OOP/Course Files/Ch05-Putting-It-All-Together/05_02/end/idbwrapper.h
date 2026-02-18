#ifndef IDBWRAPPER_H
#define IDBWRAPPER_H

#include <iostream>
#include <vector>

class IDBWrapper
{
public:
  virtual ~IDBWrapper() = default;
  virtual void saveData(const std::vector<std::string> &data) = 0;
};

#endif