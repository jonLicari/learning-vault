#include <iostream>

class Thermostat
{
public:
  // Constructor to initialize the thermostat
  Thermostat(float temp, unsigned int m, const std::string &loc)
  {
    temperature = temp;
    mode = m;
    location = loc;
  }

  // Destructor
  ~Thermostat()
  {
    std::cout << "Thermostat in " << location << " is being destroyed." << std::endl;
  }

  // Member function to display current status of the thermostat
  void displayStatus()
  {
    std::cout << "Location: " << location << " Temperature: " << temperature << "°C Mode: " << (mode == 0 ? "OFF " : (mode == 1 ? "COOLING " : "HEATING ")) << std::endl;
  }

private:
  float temperature;    // Temperature in degrees Celsius
  unsigned int mode;    // Mode (0 for OFF, 1 for COOLING, 2 for HEATING)
  std::string location; // Location of the thermostat
};

int main()
{
  // Create a Thermostat object
  Thermostat livingRoomThermostat(22.5, 1, "Living Room");

  // Display the status of the thermostat
  livingRoomThermostat.displayStatus();

  return 0;
}