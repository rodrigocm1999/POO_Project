//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_JOGO_H
#define TRABALHOPRATICO_JOGO_H


#include "Mundo.h"
#include "Imperio.h"

class Jogo {

    std::string name;

    int turn = 0;
    int phase = 1;
    Mundo world;
    Imperio kingdom;

public:

    Jogo();

    explicit Jogo(const Jogo *otherGame);

    const std::string &getName() const;

    int getTurn() const;

    int getPhase() const;

    const Mundo &getWorld() const;

    const Imperio &getKingdom() const;


    void setName(const std::string &name);
};


#endif //TRABALHOPRATICO_JOGO_H
