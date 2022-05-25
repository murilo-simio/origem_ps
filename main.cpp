#include "include/cp.hpp"
#include "include/bateria.hpp"
#include "include/moto.hpp"
#include "include/etb.hpp"
#include <cmath>
#include <iostream>

using namespace std;

void printMotoInfo(Moto motoI);
void printEtbInfo(int id, long long int uid, float soc, bool charg);
Moto motoUpdate(Moto motoI, bool accel);

int timer = 0;

int main(){

    Moto moto = Moto(85.00);

    Etb station = Etb();

    int ciclo = 0, segundos = 0;

    // Rotina 1
    for (ciclo=0;ciclo<6;ciclo++) {
        for (segundos=0;segundos<180;segundos++) {
            moto = motoUpdate(moto, true);
        }
        for (segundos=0;segundos<10;segundos++) {
            moto = motoUpdate(moto, false);
        }
    }

    // Rotina 2
    for (ciclo=0;ciclo<4;ciclo++) {
        for (segundos=0;segundos<120;segundos++) {
            moto = motoUpdate(moto, true);
        }
        for (segundos=0;segundos<12;segundos++) {
            moto = motoUpdate(moto, false);
        }
    }

    // Rotina 3
    for (segundos=0;segundos<100;segundos++){
        moto = motoUpdate(moto, true);
    }

    // Rotina 4
    for (segundos=0;segundos<32;segundos++){
        moto = motoUpdate(moto, false);
    }

    return 0;
}

void printMotoInfo(Moto motoI){
    cout << "Motorcycle plate: " << motoI.getPlate() << endl;
    cout << "Speed: " << motoI.getSpeed() << endl;
    cout << "Attached battery UID: " << motoI.getUid() << endl;
    cout << "Motorcycle battery SoC: " << motoI.getSoc() << "%" << endl;
}

void printEtbInfo(int id, long long int uid, float soc, bool charg){
    cout << "CP " << id << ": " << uid << " | " << soc << "| charging: " << charg << endl;
}

Moto motoUpdate(Moto motoI, bool accel){
    motoI.setSoc(motoI.calculaSoc(motoI.getHost(), motoI.calculaVel(accel)));
    timer++;
    if (timer%10 == 0)
        printMotoInfo(motoI);
    return motoI;
}