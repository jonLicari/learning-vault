#include "filehandler.h"
#include <fstream>

int main()
{
  FileHandler handler("input.txt"); // Resource acquisition
  // Use handler.get() to access the file...
  // ...
} // Resource is automatically released here
