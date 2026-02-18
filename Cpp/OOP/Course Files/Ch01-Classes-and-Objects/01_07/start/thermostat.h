#pragma once

#include <string>

enum THERMOSTAT_MODE {
    OFF = 0,
    COOLING,
    HEATING
};

class Thermostat {
public:
    Thermostat(float, THERMOSTAT_MODE, const std::string &);
    ~Thermostat();

    void displaySettings(void) const;

private:
    float temperature;
    THERMOSTAT_MODE mode; // 0: OFF, 1: COOLING, 2: HEATING
    std::string location; 
};