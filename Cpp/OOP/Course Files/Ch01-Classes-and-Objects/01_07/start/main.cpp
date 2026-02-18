#include "thermostat.h"

int main() {

    // create thermostat object
    Thermostat t1 = Thermostat(22.5, THERMOSTAT_MODE::OFF, "Silly Room");

    // print thermostat info
    t1.displaySettings();

    // object destroyed implicitly on program exit
    // NOP    

    return 0;
}