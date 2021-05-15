#include "Table.hpp"


void Table::prepareForks()
{
	for (size_t i = 0; i < 7; i++)
	{
		forksV.push_back(new Fork(i,i%7));
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

const std::array<Fork,7> & Table::getForks() {
	return forks;
}


const std::array<Philosopher,7> & Table::getPhilosophers() {
	return philosophers;
}

const TableSetup &Table::getSetup() {
	return setup;
}

bool Table::getIsDinner() const
{
    return isDinner;
}