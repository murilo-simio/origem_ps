#include "../../include/cp.hpp"

Cp::Cp() : state(false){
    battery = 00000;
};

void Cp::setState(bool x){
    state = x;
}

bool Cp::getState(){
    return state;
}

void Cp::setBattery(long long int id){
    battery = id;
    if (id == 0) state = false;
}

long long int Cp::getBattery(){
    return battery;
}