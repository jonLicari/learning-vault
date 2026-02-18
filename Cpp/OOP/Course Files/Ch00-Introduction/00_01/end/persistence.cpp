#include <iostream>

class PersistenceManager
{
public:
  virtual void save(const std::string &data) = 0;
  virtual void deleteData(const std::string &data) = 0;
};

class LocalPersistence : public PersistenceManager
{
public:
  void save(const std::string &data) override
  {
    std::cout << "Saving data locally: " << data << std::endl;
  }

  void deleteData(const std::string &data) override
  {
    std::cout << "Deleting data locally: " << data << std::endl;
  }
};

class CloudStorage : public PersistenceManager
{
public:
  void save(const std::string &data) override
  {
    std::cout << "Saving data to the cloud: " << data << std::endl;
  }

  void deleteData(const std::string &data) override
  {
    std::cout << "Deleting data from the cloud: " << data << std::endl;
  }
};

int main()
{
  LocalPersistence localStorage;
  CloudStorage cloudStorage;

  localStorage.save("Local data"); // Output: Saving data locally: Local data
  cloudStorage.save("Cloud data"); // Output: Saving data to the cloud: Cloud data

  localStorage.deleteData("Local data"); // Output: Deleting data locally: Local data
  cloudStorage.deleteData("Cloud data"); // Output: Deleting data from the cloud: Cloud data

  return 0;
}