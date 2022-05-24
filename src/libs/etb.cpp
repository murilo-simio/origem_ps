#include "../../include/etb.hpp"

Etb::Etb(){
    setUid();
    for(int i=1;i<=CP;i++){
        cp[i] = Cp();
    }
}

void Etb::setUid(){
    uid = rand() % 10000000 + 1;
}

long int Etb::getUid(){
    return uid;
}

void Etb::getCp(){    
    for(int i=1;i<=CP;i++){
        std::cout<<"CP n"<<i<<": ";
        if(cp[i].getState()){
            std::cout<<"charging";
        }else{
            std::cout<<"idle";
        }
        std::cout<<std::endl;
    }
}

bool Etb::getCp(int value){
    std::cout<<"CP n"<<value<<": ";
        if(cp[value].getState()){
            std::cout<<"charging";
        }else{
            std::cout<<"idle";
        }
        std::cout<<std::endl;
    return cp[value].getState();
}
