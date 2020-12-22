//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_REFUGIO_H
#define TRABALHOPRATICO_REFUGIO_H

#include "Ilha.h"

class Refugio : public Ilha {

	static int idCounter;

public:
	std::string getType() const override { return Ilha::getType() + "_Refugio"; }

	Refugio();

	Territorio *createCopy() const override;
};


#endif //TRABALHOPRATICO_REFUGIO_H
