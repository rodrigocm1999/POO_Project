//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_JOGO_H
#define TRABALHOPRATICO_JOGO_H


#include "Mundo.h"
#include "Imperio.h"

class Jogo {

private:

    std::string name;
    int turn = -1;
    int phase = -1;
    Mundo world;
    Imperio kingdom;

    Territorio *getWorldTerritoryByName(const std::string &name) const;

    Territorio *getKingdomTerritoryByName(const std::string &name) const;

public:

    Jogo();

    explicit Jogo(const Jogo *otherGame);

    void addTerritoryToWorld(Territorio *newTerritory);

    int conquer(std::string &territoryName);

    bool isInProgress() const { return turn > 0; }

    const std::string &getName() const { return name; }

    int getTurn() const { return turn; }

    int getPhase() const { return phase; }

    const Mundo &getWorld() const { return world; }

    const Imperio &getKingdom() const { return kingdom; }

    void setName(const std::string &_name) { name = _name; }

    const Territorio *getTerritoryByName(const std::string &name) const;

    std::vector<Territorio *> getAllTerritories() const;

    void printGame(std::ostream &out) const;
};


#endif //TRABALHOPRATICO_JOGO_H
