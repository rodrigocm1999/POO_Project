//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_ILHA_H
#define TRABALHOPRATICO_ILHA_H


#include "Territorio.h"

class Ilha : public Territorio {

public:
    bool isIsland() const { return true; }

    std::string getType() const { return "Ilha"; }

    Ilha();
};


#endif //TRABALHOPRATICO_ILHA_H
