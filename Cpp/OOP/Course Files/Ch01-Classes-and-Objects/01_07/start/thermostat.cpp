#include "thermostat.h"
#include <iostream>

Thermostat::Thermostat(float t, THERMOSTAT_MODE m, const std::string & s) {
    this->temperature = t;
    this->mode = m;
    this->location = s;
}

Thermostat::~Thermostat() {
    std::cout << "Object is dead. You hear me?? DEAD!" << std::endl;
}

void Thermostat::displaySettings(void) const {
    std::cout << "Temperature = " << this->temperature << " C" \
    << ", Mode = " << this->mode \
    << ", Location = " << this->location \
    << std::endl;
}