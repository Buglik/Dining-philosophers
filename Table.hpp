#pragma once
#include <array>
#include "TableSetup.hpp"
#include "Fork.hpp"
#include "Phiosopher.hpp"
#include <vector>

class Table
{
public:
	// Table();

private:
    bool isDinner;
    TableSetup setup;
    const static int amount = 7;

	std::vector<Fork*> forksV;


	std::array<Fork,amount> forks
	{
	   {
			{ 1, 1 },
			{ 2, 2 },
			{ 3, 3 },
			{ 4, 4 },
			{ 5, 5 },
			{ 6, 6 },
			{ 7, 1 },
		 }
	};


	std::array<Philosopher,amount> philosophers
	{
	   {
			{ 1, "Austin", setup, forks[0], forks[1] },
			{ 2, "Barnie", setup, forks[1], forks[2] },
			{ 3, "Cedric", setup, forks[2], forks[3] },
			{ 4, "Darren", setup, forks[3], forks[4] },
			{ 5, "Elijah", setup, forks[4], forks[5] },
			{ 6, "Freddy", setup, forks[5], forks[6] },
			{ 7, "George", setup, forks[6], forks[0] },
		  }
	};

public:
	void prepareForks();
	void dinnerStart();
	void dinnerStop();
	const std::array<Philosopher,7> &getPhilosophers();
	const std::array<Fork,7> &getForks();
	const TableSetup &getSetup();
    bool getIsDinner() const;

};
