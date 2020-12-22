//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_PLANICIE_H
#define TRABALHOPRATICO_PLANICIE_H

#include "Continente.h"

class Planicie : public Continente {

	static int idCounter;

public:
    std::string getType() const override { return Continente::getType() + "_Planicie"; }

    Planicie();

	void updateValues(int turn, int year) override;

	Territorio *createCopy() const override;
};


#endif //TRABALHOPRATICO_PLANICIE_H
