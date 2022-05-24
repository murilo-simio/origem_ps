#include "../../include/cp.hpp"

Cp::Cp() : state(false){};

void Cp::changeState(){
    state = !state;
}

bool Cp::getState(){
    return state;
}