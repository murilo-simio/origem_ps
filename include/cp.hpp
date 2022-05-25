#ifndef CP_HPP
#define CP_HPP

#include <iostream>
#include "defines.hpp"
#include "bateria.hpp"

class Cp
{
private:
    bool state;  // 0 - Idle, 1 - Charging
    long long int battery;
public:
    void setState(bool x);
    bool getState();
    void setBattery(long long int id);
    long long int getBattery();
    Cp();
};

#endif  // CP_HPPs