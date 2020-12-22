//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_MINA_H
#define TRABALHOPRATICO_MINA_H

#include "Continente.h"

class Mina : public Continente {

	static int idCounter;

public:
    std::string getType() const override { return Continente::getType() + "_Mina"; }

    Mina();

	void updateValues(int turn, int year) override;

	Territorio *createCopy() const override;
};

#endif //TRABALHOPRATICO_MINA_H
