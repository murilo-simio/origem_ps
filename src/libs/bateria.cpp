#include "../../include/bateria.hpp"

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

void Bateria::setState(){
    state = !state;
}

bool Bateria::getState(){
    return state;
}

void Bateria::setHost(int moto){
    if(!getState())
        if(moto > -1) setState();
    if(getState())
        if(moto < 0) setState();
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
    soc = value;
}

float Bateria::getSoc(){
    return soc;
}

float Bateria::calculaSoc(int host, float veloc){
    float x = getSoc();
    if(host == 0){
        x += 0.05;
    }else if(veloc){
        x = x - 0.01 - (pow((veloc/MAX_SPEED),2) * 0.05);
    }else{
        x -= 0.01;
    }
    setSoc(x);
    return getSoc();
}