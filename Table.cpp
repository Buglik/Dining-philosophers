#include "Table.hpp"

Table::Table(int n) : amount(n)
{
	prepareForks();
	preparePhilosophers();
}

void Table::prepareForks()
{
	for (size_t i = 0; i < amount; i++)
	{
		forksV.push_back(new Fork(i, i % amount));
	}
}

void Table::preparePhilosophers()
{
	for (size_t i = 0; i < amount; i++)
	{
		std::string name = "Philosopher ";
		name += std::to_string(i);
		philosophersV.push_back(new Philosopher(i, name, setup, forksV.at(i), forksV.at((i + 1) % amount)));
	}
}

void Table::dinnerStart()
{
	isDinner = true;
	setup.talk.letEveryoneKnow();
}

void Table::dinnerStop()
{
	setup.setStatus(true);
	isDinner = false;
}

std::vector<Fork *> &Table::getForks()
{
	return forksV;
}

std::vector<Philosopher *> &Table::getPhilosophers()
{
	return philosophersV;
}

const TableSetup &Table::getSetup()
{
	return setup;
}

bool Table::getIsDinner() const
{
	return isDinner;
}