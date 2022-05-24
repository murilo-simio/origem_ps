#ifndef CP_HPP
#define CP_HPP

#include <iostream>

class Cp
{
private:
    bool state;  // 0 - Idle, 1 - Charging
public:
    void changeState();
    bool getState();
    Cp();
};

#endif  // CP_HPPs