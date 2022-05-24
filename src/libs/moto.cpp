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

void Moto::setSpeed(float value){
    if(value < MAX_SPEED || value > 0){
        speed = value;
    }else if(value > MAX_SPEED){
        speed = MAX_SPEED;
    }else{
        speed = 0;
    }
}

float Moto::getSpeed(){
    return speed;
}

float Moto::calculaVel(bool acell){
    float veloc = getSpeed();
    if(acell){
        veloc += 0.2;
    }else{
        veloc -= 2;
    }
    setSpeed(veloc);
    return getSpeed();
}