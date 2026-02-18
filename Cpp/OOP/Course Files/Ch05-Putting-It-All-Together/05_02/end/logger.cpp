#include "logger.h"
#include <ctime>

void Logger::log(const std::string &message)
{
  std::cout << "LOG: " << message << " at "
            << std::time(nullptr) << "\n";
}