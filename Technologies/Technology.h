//
// Created by Rodrigo on 17/12/2020.
//

#ifndef TRABALHOPRATICO_TECHNOLOGY_H
#define TRABALHOPRATICO_TECHNOLOGY_H

#include <string>

class Kingdom;

class Technology {

	std::string name;
	int cost;

public:

	Technology(const std::string &name, int cost);

	const std::string &getName() const { return name; }

	int getCost() const { return cost; }

	virtual void makeChanges(Kingdom* kingdom) const;
};


#endif //TRABALHOPRATICO_TECHNOLOGY_H
