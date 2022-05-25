#ifndef BATERIA_HPP
#define BATERIA_HPP

#include "defines.hpp"
#include <cstdlib>
#include <cmath>

class Bateria
{
private:
    long long int uid;
    float soc;
    bool state; // 0 - Idle, 1 - Attached
    int host; // -1 - Deattached, 0 - ETB, 1 - Moto
public:
    Bateria();
    Bateria(float carga);
    Bateria(float carga, int local);
    void setState(bool x);
    bool getState();
    void setHost(int moto);
    int getHost();
    void setUid();
    long long int getUid();
    void setSoc(float value);
    float getSoc();
    float calculaSoc(int host, float veloc = 0.0);
};

#endif  // BATERIA_HPP