#include "../../include/bateria.hpp"
#include <iostream>

Bateria::Bateria() : state(false){
    setUid();
    soc = 0;
}

Bateria::Bateria(float carga) : soc(carga){
    setUid();
    state = false;
}

Bateria::Bateria(float carga, int local) : soc(carga){
    setUid();
    state = true;
    setHost(local);
}

void Bateria::setState(bool x){
    state = x;
    if( getHost() == -1){
        state = false;
    }else {
        state = true;
    }
}

bool Bateria::getState(){
    return state;
}

void Bateria::setHost(int moto){
    host = moto;
}

int Bateria::getHost(){
    return host;
}

void Bateria::setUid(){
    uid = rand() % 100000 + 1;
}

long long int Bateria::getUid(){
    return uid;
}

void Bateria::setSoc(float value){
    if (value < 0) {
        soc = 0;
    }else if (soc > 100.0){
        soc = 100.000000;
    }else{
        soc = value;
    }
}

float Bateria::getSoc(){
    return soc;
}

float Bateria::calculaSoc(int host, float veloc){
    float x = getSoc();
    if(host == 0){
        x = (float) (x + 0.05);
    }else if(veloc > 0){
        x = x - 0.01 - (pow((veloc/MAX_SPEED),2) * 0.05);
    }else{
        x -= 0.01;
    }
    setSoc(x);
    return getSoc();
}