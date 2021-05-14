#include "Table.hpp"


Table::Table(int amount) : amount(amount)
{
	prepareForks();
	// preparePhilosophers();
}


void Table::preparePhilosophers()
{
	for (size_t i = 0; i < amount; i++)
	{
		std::string name = "Philosopher ";
		name += std::to_string(i);
		philosophers.push_back(Philosopher(i,name,setup,forks.at(i),forks.at(i%amount)));

	}
}

void Table::prepareForks()
{
	for (size_t i = 0; i < amount; i++)
	{
		forks.push_back(Fork(i,i%amount));
	}
}

void Table::dinnerStart()
{
    isDinner=true;
	setup.talk.letEveryoneKnow();
}

void Table::dinnerStop()
{
	setup.setStatus(true);
    isDinner=false;
}

const std::vector<Fork> & Table::getForks() {
	return forks;
}


	const std::vector<Philosopher> & Table::getPhilosophers() {
		return philosophers;
	}

	const TableSetup &Table::getSetup() {
		return setup;
	}

bool Table::getIsDinner() const
{
    return isDinner;
}