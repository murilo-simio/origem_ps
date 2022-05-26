#include "include/cp.hpp"
#include "include/bateria.hpp"
#include "include/moto.hpp"
#include "include/etb.hpp"
#include "include/defines.hpp"
#include <cmath>
#include <iostream>
#include <array>

using namespace std;

void printMotoInfo(Moto motoI);
void printEtbInfo(Cp ponto, int id, Bateria batt);
Moto motoUpdate(Moto motoI, bool accel);
Bateria trocaBaterias(Moto velha, Etb local);
Moto colocaBateria(Moto motoI, Bateria batt);
array <Bateria,8> etbInfo(array <Bateria,8> batt, Etb ponto);

int timer = 0;

int main(){

    Moto moto = Moto(85.00);

    Etb station = Etb();

    array <Bateria,8> baterias;

    baterias[0].setSoc(100);
    baterias[1].setSoc(100);
    baterias[2].setSoc(100);
    baterias[3].setSoc(70);
    baterias[4].setSoc(60);
    baterias[5].setSoc(50);

    baterias = etbInfo(baterias, station);

    for (int i=0;i<6;i++){
        baterias[i] = station.toAttach(i, baterias[i]);
        baterias[i] = station.chargeBatt(i, baterias[i]);
    }

    int ciclo = 0, segundos = 0;

    // Rotina 1
    for (ciclo=0;ciclo<6;ciclo++) {
        for (segundos=0;segundos<180;segundos++) {
            moto = motoUpdate(moto, true);
            baterias = etbInfo(baterias, station);
        }
        for (segundos=0;segundos<10;segundos++) {
            moto = motoUpdate(moto, false);
            baterias = etbInfo(baterias, station);
        }
    }

    // Rotina 2
    for (ciclo=0;ciclo<4;ciclo++) {
        for (segundos=0;segundos<120;segundos++) {
            moto = motoUpdate(moto, true);
            baterias = etbInfo(baterias, station);
        }
        for (segundos=0;segundos<12;segundos++) {
            moto = motoUpdate(moto, false);
            baterias = etbInfo(baterias, station);
        }
    }

    // Rotina 3
    for (segundos=0;segundos<100;segundos++){
        moto = motoUpdate(moto, true);
        baterias = etbInfo(baterias, station);
    }

    // Rotina 4
    for (segundos=0;segundos<32;segundos++){
        moto = motoUpdate(moto, false);
        baterias = etbInfo(baterias, station);
    }

    // Rotina 5 - Troca de Bateria
    baterias[6] = trocaBaterias(moto, station);
    baterias[6] = station.toAttach(6, baterias[6]);

    moto = colocaBateria(moto, baterias[0]);
    baterias[0] = station.toDetach(0, baterias[0]);

    timer=10;
    printMotoInfo(moto);
    etbInfo(baterias, station);

    return 0;
}

Bateria trocaBaterias(Moto velha, Etb local){
    Bateria batt;
    batt.setSoc(velha.getSoc());
    batt.setUid(velha.getUid());
    return batt;
}

Moto colocaBateria(Moto motoI, Bateria batt){
    motoI.setSoc(batt.getSoc());
    motoI.setHost(1);
    motoI.setUid(batt.getUid());
    return motoI;
}

void printMotoInfo(Moto motoI){
    cout << "=======================================" << endl;
    cout << "Motorcycle plate: " << motoI.getPlate() << endl;
    cout << "Speed: " << motoI.getSpeed() << endl;
    cout << "Attached battery UID: " << motoI.getUid() << endl;
    cout << "Motorcycle battery SoC: " << motoI.getSoc() << "%" << endl << endl;
}

void printEtbInfo(Cp ponto, int id, Bateria batt){
    cout << "[CP " << id << ": " << ponto.getBattery() << " | ";
    cout << batt.getSoc() << "% | charging: ";
    if (ponto.getState()){
        cout << "YES" << endl;
    }else{
        cout << "NO]" << endl;
    }
}

array <Bateria,8> etbInfo(array <Bateria,8> batt, Etb ponto){
    for (int i=0;i<CP;i++){
        batt[i] = ponto.chargeBatt(i, batt[i]);
    }
    if (timer%10 == 0){
        for (int i=0;i<CP;i++) {
            printEtbInfo(ponto.getCp(i), i, batt[i]);
        }
    }
    return batt;
}

Moto motoUpdate(Moto motoI, bool accel){
    motoI.setSoc(motoI.calculaSoc(motoI.getHost(), motoI.calculaVel(accel)));
    timer++;
    if (timer%10 == 0)
        printMotoInfo(motoI);
    return motoI;
}