//
// Created by Rodrigo on 17/11/2020.
//

#ifndef TRABALHOPRATICO_MUNDO_H
#define TRABALHOPRATICO_MUNDO_H


#include <vector>
#include "Territorios/Territorio.h"

class Mundo {

    std::vector<Territorio *> territories;

public:

    virtual ~Mundo();

    const std::vector<Territorio *> &getTerritories() const;

    void setTerritories(const std::vector<Territorio *> &territories);

    void addTerritory(Territorio *territory);

    void gotConquered(const Territorio *territory);

	void print(std::ostream &out) const;

};


#endif //TRABALHOPRATICO_MUNDO_H
