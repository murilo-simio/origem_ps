#ifndef MOTO_HPP
#define MOTO_HPP

#include "bateria.hpp"
#include "defines.hpp"

#include <string>
#include <cstdlib>


class Moto: public Bateria
{
private:
    bool state; // 0 - Standby, 1 - On
    std::string plate;
    float speed;
    Bateria bateria;
public:
    Moto(float carga);
    void setState();
    bool getState();
    void setPlate();
    std::string getPlate();
    void setSpeed(float value);
    float getSpeed();
    float calculaVel(bool acell, int seg = 1);
    Bateria getBateria();
    void setBateria(Bateria batt);
};

#endif // MOTO_HPP