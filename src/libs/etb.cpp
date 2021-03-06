#include "../../include/etb.hpp"

Etb::Etb(){
    setUid();
    for(int i=0;i<CP;i++){
        cp[i] = Cp();
    }
}

void Etb::setUid(){
    uid = rand() % 10000000 + 1;
}

long int Etb::getUid(){
    return uid;
}

Cp Etb::getCp(int value){
    return cp[value];
}

Bateria Etb::toAttach(int id, Bateria batt){
    batt.setHost(0);
    cp[id].setState(true);
    cp[id].setBattery(batt.getUid());
    return batt;
}

Bateria Etb::chargeBatt(int id, Bateria batt){
    if (batt.getSoc() < 100 && cp[id].getState() != false) {
        batt.calculaSoc(0);
        cp[id].setState(true);
    } else {
        cp[id].setState(false);
    }
    return batt;
}

Bateria Etb::toDetach(int id, Bateria batt){
    batt.setHost(-1);
    batt.setSoc(0);
    cp[id].setBattery(0);
    return batt;
}

int Etb::countBatt(){
    int cont = 0; 
    for (int i=0;i<CP;i++) {
        if (cp[i].getBattery() != 0) cont++;
    }
    return cont;
}

int Etb::countCharg(){
    int cont = 0;
    for (int i=0;i<CP;i++) {
        if (cp[i].getState()) cont++;
    }
    return cont;
}

int Etb::timeToCharge(Bateria batt){
    float carga = (100 - batt.getSoc());
    int time = (int) ceil(carga / 0.05);
    return time;
}