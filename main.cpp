#include "include/cp.hpp"
#include "include/bateria.hpp"
#include "include/moto.hpp"
#include "include/etb.hpp"
#include <cmath>
#include <iostream>

using namespace std;

void printMotoInfo(string plate, float veloc, long long int batt, float carga);
void printEtbInfo(int id, long long int uid, float soc, bool charg);

int main(){

    Moto moto = Moto(85.00);

    Etb station = Etb();

    int ciclo = 0, segundos = 0, timer = 0;

    // Rotina 1
    for (ciclo=0;ciclo<6;ciclo++) {
        for (segundos=0;segundos<180;segundos++) {
            moto.setSoc(moto.calculaSoc(moto.getHost(), moto.calculaVel(true)));
            timer++;
            if (timer%10 == 0)
                printMotoInfo(moto.getPlate(), moto.getSpeed(), moto.getUid(), moto.getSoc());
        }
        for (segundos=0;segundos<10;segundos++) {
            moto.setSoc(moto.calculaSoc(moto.getHost(), moto.calculaVel(false)));
            timer++;
            if (timer%10 == 0)
                printMotoInfo(moto.getPlate(), moto.getSpeed(), moto.getUid(), moto.getSoc());
        }
    }

    // Rotina 2
    for (ciclo=0;ciclo<4;ciclo++) {
        for (segundos=0;segundos<120;segundos++) {
            moto.setSoc(moto.calculaSoc(moto.getHost(), moto.calculaVel(true)));
            timer++;
            if (timer%10 == 0)
                printMotoInfo(moto.getPlate(), moto.getSpeed(), moto.getUid(), moto.getSoc());
        }
        for (segundos=0;segundos<12;segundos++) {
            moto.setSoc(moto.calculaSoc(moto.getHost(), moto.calculaVel(false)));
            timer++;
            if (timer%10 == 0)
                printMotoInfo(moto.getPlate(), moto.getSpeed(), moto.getUid(), moto.getSoc());
        }
    }

    // Rotina 3
    for (segundos=0;segundos<100;segundos++){
        moto.setSoc(moto.calculaSoc(moto.getHost(), moto.calculaVel(true)));
        timer++;
        if (timer%10 == 0)
            printMotoInfo(moto.getPlate(), moto.getSpeed(), moto.getUid(), moto.getSoc());
    }

    // Rotina 4
    for (segundos=0;segundos<32;segundos++){
        moto.setSoc(moto.calculaSoc(moto.getHost(), moto.calculaVel(false)));
        timer++;
        if (timer%10 == 0)
            printMotoInfo(moto.getPlate(), moto.getSpeed(), moto.getUid(), moto.getSoc());
    }

    return 0;
}

void printMotoInfo(string plate, float veloc, long long int batt, float carga){
    cout << "Motorcycle plate: " << plate << endl;
    cout << "Speed: " << veloc << endl;
    cout << "Attached battery UID: " << batt << endl;
    cout << "Motorcycle battery SoC: " << carga << "%" << endl;
}

void printEtbInfo(int id, long long int uid, float soc, bool charg){
    cout << "CP " << id << ": " << uid << " | " << soc << "| charging: " << charg << endl;
}