//
// Created by Rodrigo on 17/12/2020.
//

#ifndef TRABALHOPRATICO_BANCOCENTRAL_H
#define TRABALHOPRATICO_BANCOCENTRAL_H

#include "Technology.h"

class BancoCentral : public Technology {

public:
	BancoCentral():Technology("BancoCentral",3){}

	void makeChanges(Kingdom *kingdom) const override;
};


#endif //TRABALHOPRATICO_BANCOCENTRAL_H
