#ifndef ETB_HPP
#define ETB_HPP

#include "bateria.hpp"
#include "cp.hpp"
#include "defines.hpp"

#include <iostream>
#include <array>
#include <cstdlib>
#include <cmath>

class Etb: public Cp, public Bateria
{
private:
    long int uid;
    std::array <Cp,CP> cp;
public:
    Etb();
    void setUid();
    long int getUid();
    Cp getCp(int value);
    Bateria toAttach(int id, Bateria batt);
    Bateria chargeBatt(int id, Bateria batt);
    Bateria toDetach(int id, Bateria batt);
    int countBatt();
    int countCharg();
    int timeToCharge(Bateria batt);
};

#endif // ETB_HPP