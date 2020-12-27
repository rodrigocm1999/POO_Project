//
// Created by Rodrigo on 17/12/2020.
//

#ifndef TRABALHOPRATICO_MISSEISTELEGUIADOS_H
#define TRABALHOPRATICO_MISSEISTELEGUIADOS_H

#include "Technology.h"

class MisseisTeleguiados : public Technology {

public:
	MisseisTeleguiados():Technology("MisseisTeleguiados",4){}

	Technology *createCopy() const override;
};


#endif //TRABALHOPRATICO_MISSEISTELEGUIADOS_H
