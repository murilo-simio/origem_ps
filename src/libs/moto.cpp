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
    if(value > MAX_SPEED){
        speed = MAX_SPEED;
    }else if(value < 0){
        speed = 0;
    }else{
        speed = value;
    }
}

float Moto::getSpeed(){
    return speed;
}

float Moto::calculaVel(bool acell, int seg){
    float veloc = getSpeed();
    
    if(acell){
        for (int i=0;i<seg;i++) {
            veloc += 0.2;
        }
    }else{
        for (int i=0;i<seg;i++) {
            veloc -= 2;
        }
    }
    
    setSpeed(veloc);
    return getSpeed();
}

Bateria Moto::getBateria(){
    return bateria;
}