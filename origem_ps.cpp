#include <iostream>

#include "include/bateria.hpp"
#include "include/moto.hpp"
#include "include/etb.hpp"

int main(){
    // Bateria b1 = Bateria();
    // Bateria b2 = Bateria(3.95);
    // Bateria b3 = Bateria(4.25, 1);

    // float a,b,c;

    // b=b2.getSoc();
    // c=b3.getSoc();

    // std::cout<< b << " "<< c << std::endl;
    // b2.setSoc(16);
    // b=b2.getSoc();
    // std::cout<< b << " "<< c << std::endl;

    // Moto moto = Moto(3.95);
    // std::cout<<moto.getSoc()<<std::endl;

    // std::cout<<moto.Bateria::getState()<<std::endl;
    // std::cout<<b2.Bateria::getState()<<std::endl;
    
    Etb testa = Etb();
    testa.getCp();
    std::cout<< testa.getCp(2);

    return 0;
}