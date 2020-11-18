//
// Created by cenas on 17/11/2020.
//

#ifndef TRABALHOPRATICO_REFUGIO_H
#define TRABALHOPRATICO_REFUGIO_H

#include "Ilha.h"

class Refugio : public Ilha {

public:
	std::string getType() const override { return Ilha::getType() + "_Refugio"; }

	Refugio() {
		static int idCounter = 0;
		this->name = "Refugio" + std::to_string(++idCounter);
		this->resistance = 9;
		this->goldProduction = 1;
	}

};


#endif //TRABALHOPRATICO_REFUGIO_H
