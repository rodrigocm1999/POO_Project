//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_PESCARIA_H
#define TRABALHOPRATICO_PESCARIA_H

#include "Ilha.h"

class Pescaria : public Ilha{

	static int idCounter;

public:
    std::string getType() const override { return Ilha::getType() + "_Pescaria"; }

    Pescaria();

	void updateValues(int turn, int year) override;

	Territorio *createCopy() const override;
};


#endif //TRABALHOPRATICO_PESCARIA_H
