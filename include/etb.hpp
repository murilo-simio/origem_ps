#ifndef ETB_HPP
#define ETB_HPP

#include <iostream>
#include <array>
#include <cstdlib>

#include "cp.hpp"

#define CP 8

class Etb: public Cp
{
private:
    long int uid;
    std::array <Cp,CP> cp;
public:
    Etb();
    void setUid();
    long int getUid();
    void getCp();
    bool getCp(int value);
};

#endif // ETB_HPP