#include "include/cp.hpp"
#include "include/bateria.hpp"
#include "include/moto.hpp"
#include "include/etb.hpp"
#include <cmath>
#include <iostream>

using namespace std;

void printMotoInfo(string plate, float veloc, long long int batt, float carga);

int main(){

    Moto moto = Moto(85.00);
    moto.setSpeed(40.0);

    moto.setSoc(moto.calculaSoc(moto.getSoc(), moto.getHost(), moto.calculaVel(true)));
    moto.setSoc(moto.calculaSoc(moto.getSoc(), moto.getHost(), moto.calculaVel(true)));
    moto.setSoc(moto.calculaSoc(moto.getSoc(), moto.getHost(), moto.calculaVel(true)));

    printMotoInfo(moto.getPlate(), moto.getSpeed(), moto.getUid(), moto.getSoc());

    return 0;
}

void printMotoInfo(string plate, float veloc, long long int batt, float carga){
    cout << "Motorcycle plate: " << plate << endl;
    cout << "Speed: " << veloc << endl;
    cout << "Attached battery UID: " << batt << endl;
    cout << "Motorcycle battery SoC: " << carga << "%" << endl;
}