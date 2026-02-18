#ifndef LOGGER_H
#define LOGGER_H

#include "ilogger.h"
#include <iostream>

// logger.h & logger.cpp
class Logger : public ILogger
{
public:
  void log(const std::string &message) override;
};

#endif