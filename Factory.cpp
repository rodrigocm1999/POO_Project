//
// Created by Rodrigo on 21/12/2020.
//

#include "Factory.h"

#include "Territorios/Castelo.h"
#include "Territorios/Continente.h"
#include "Territorios/Duna.h"
#include "Territorios/Fortaleza.h"
#include "Territorios/Ilha.h"
#include "Territorios/Mina.h"
#include "Territorios/Montanha.h"
#include "Territorios/Pescaria.h"
#include "Territorios/Planicie.h"
#include "Territorios/Refugio.h"
#include "Territorios/Territorio.h"
#include "Territorios/TerritorioInicial.h"

#include "Technologies/BancoCentral.h"
#include "Technologies/DroneMilitar.h"
#include "Technologies/BolsaValores.h"
#include "Technologies/DefesasTerritoriais.h"
#include "Technologies/MisseisTeleguiados.h"


Territorio *Factory::createTerritoryFromType(const std::string &type) {
	if (type == "planicie") return new Planicie;
	if (type == "montanha") return new Montanha;
	if (type == "fortaleza") return new Fortaleza;
	if (type == "mina") return new Mina;
	if (type == "duna") return new Duna;
	if (type == "castelo") return new Castelo;
	if (type == "refugio") return new Refugio;
	if (type == "pescaria") return new Pescaria;
	if (type == "continent") return new Continente;
	return nullptr;
}

Technology *Factory::createTechnologyFromType(const std::string &type) {
	if (type == "DronesMilitares") return new DroneMilitar;
	if (type == "BolsaValores") return new BolsaValores;
	if (type == "BancoCentral") return new BancoCentral;
	if (type == "DefesasTerritoriais") return new DefesasTerritoriais;
	if (type == "MisseisTeleguiados") return new MisseisTeleguiados;
	return nullptr;
}
