#include <fstream>

int main()
{
  FILE *file = fopen("input.txt", "r");
  if (!file)
  {
    throw std::runtime_error("Could not open file");
  }

  try
  {
    // Use the file...
  }
  catch (...)
  {
    fclose(file); // Close file on error
    throw;        // Re-throw the exception
  }

  fclose(file);
}