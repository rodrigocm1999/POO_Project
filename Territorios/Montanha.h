//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_MONTANHA_H
#define TRABALHOPRATICO_MONTANHA_H

#include "Continente.h"

class Montanha : public Continente {

	static int idCounter;
	int turnCounter;

public:
	std::string getType() const override { return Continente::getType() + "_Montanha"; }

	Montanha();

	void updateValues(int turn, int year) override;

	Territorio &operator=(const Territorio *other) override;

	Territorio *createCopy() const override;
};


#endif //TRABALHOPRATICO_MONTANHA_H
