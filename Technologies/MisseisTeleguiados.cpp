//
// Created by Rodrigo on 17/12/2020.
//

#include "MisseisTeleguiados.h"

Technology *MisseisTeleguiados::createCopy() const {
	return new MisseisTeleguiados(*this);
}
