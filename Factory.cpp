//
// Created by Rodrigo on 21/12/2020.
//

#include "Factory.h"

#include "Territorios/Continente.h"
#include "Territorios/Ilha.h"
#include "Territorios/Castelo.h"
#include "Territorios/Duna.h"
#include "Territorios/Fortaleza.h"
#include "Territorios/Mina.h"
#include "Territorios/Montanha.h"
#include "Territorios/Pescaria.h"
#include "Territorios/Planicie.h"
#include "Territorios/Refugio.h"

#include "Technologies/BancoCentral.h"
#include "Technologies/DroneMilitar.h"
#include "Technologies/BolsaValores.h"
#include "Technologies/DefesasTerritoriais.h"
#include "Technologies/MisseisTeleguiados.h"

#include "Constants.h"

Territorio *Factory::createTerritoryFromType(const std::string &type) {
	if (type == TERR_PLANICIE) return new Planicie;
	if (type == TERR_MONTANHA) return new Montanha;
	if (type == TERR_FORTALEZA) return new Fortaleza;
	if (type == TERR_MINA) return new Mina;
	if (type == TERR_DUNA) return new Duna;
	if (type == TERR_CASTELO) return new Castelo;
	if (type == TERR_REFUGIO) return new Refugio;
	if (type == TERR_PESCARIA) return new Pescaria;
	return nullptr;
}

Technology *Factory::createTechnologyFromType(const std::string &type) {
	if (type == TEC_DRONE) return new DroneMilitar;
	if (type == TEC_BOLSA) return new BolsaValores;
	if (type == TEC_BANCO) return new BancoCentral;
	if (type == TEC_DEFESAS) return new DefesasTerritoriais;
	if (type == TEC_MISSEIS) return new MisseisTeleguiados;
	return nullptr;
}
