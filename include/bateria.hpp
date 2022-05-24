#ifndef BATERIA_HPP
#define BATERIA_HPP

#include <cstdlib>

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
    void setState();
    bool getState();
    void setHost(int moto);
    int getHost();
    void setUid();
    long long int getUid();
    void setSoc(float value);
    float getSoc();
};

#endif  // BATERIA_HPP