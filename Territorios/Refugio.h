//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_REFUGIO_H
#define TRABALHOPRATICO_REFUGIO_H

#include "Ilha.h"

class Refugio : public Ilha {

public:
	std::string getType() const override { return Ilha::getType() + "_Refugio"; }

	Refugio();

};


#endif //TRABALHOPRATICO_REFUGIO_H
