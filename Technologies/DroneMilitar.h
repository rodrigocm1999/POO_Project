//
// Created by Rodrigo on 17/12/2020.
//

#ifndef TRABALHOPRATICO_DRONEMILITAR_H
#define TRABALHOPRATICO_DRONEMILITAR_H

#include "Technology.h"

class DroneMilitar : public Technology {

public:
	DroneMilitar():Technology("DroneMilitar",3){}

	void makeChanges(Kingdom *kingdom) const override;
};


#endif //TRABALHOPRATICO_DRONEMILITAR_H
