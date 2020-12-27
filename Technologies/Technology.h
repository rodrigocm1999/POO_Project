//
// Created by Rodrigo on 17/12/2020.
//

#ifndef TRABALHOPRATICO_TECHNOLOGY_H
#define TRABALHOPRATICO_TECHNOLOGY_H

#include <string>
#include <ostream>

class Kingdom;

class Technology {

	std::string name;
	int cost;

public:

	Technology(const std::string &name, int cost);

	const std::string &getName() const { return name; }

	int getCost() const { return cost; }

	virtual void makeChanges(Kingdom *kingdom) const;

	virtual Technology *createCopy() const = 0;

	friend std::ostream &operator<<(std::ostream &os, const Technology &technology);
};


#endif //TRABALHOPRATICO_TECHNOLOGY_H
