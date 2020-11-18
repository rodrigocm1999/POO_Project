//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_CONTINENTE_H
#define TRABALHOPRATICO_CONTINENTE_H


#include "Territorio.h"

class Continente : public Territorio {

public:
    bool isContinent() const { return true; }

    std::string getType() const { return "Continente"; }

};


#endif //TRABALHOPRATICO_CONTINENTE_H
