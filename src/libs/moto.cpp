#include "../../include/moto.hpp"

Moto::Moto(float carga){
    setSoc(carga);
    setHost(1);
    speed = 0;
    state = false;
    setPlate();
}

void Moto::setPlate(){
    int plate_n = rand() % 10000000 + 1;
    plate = std::to_string(plate_n);
}

void Moto::setState(){
    state = !state;
}

bool Moto::getState(){
    return state;
}

std::string Moto::getPlate(){
    return plate;
}

void Moto::setSpeed(int value){
    speed = value;
}

int Moto::getSpeed(){
    return speed;
}