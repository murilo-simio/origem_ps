#ifndef MOTO_HPP
#define MOTO_HPP

#include "bateria.hpp"

#include <string>
#include <cstdlib>

#define MAX_SPEED 60

class Moto: public Bateria
{
private:
    bool state; // 0 - Standby, 1 - On
    std::string plate;
    int speed;
    Bateria bateria;
public:
    Moto(float carga);
    void setState();
    bool getState();
    void setPlate();
    std::string getPlate();
    void setSpeed(int value);
    int getSpeed();
};

#endif // MOTO_HPP