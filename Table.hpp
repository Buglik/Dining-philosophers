#pragma once
#include <array>
#include "TableSetup.hpp"
#include "Fork.hpp"
#include "Phiosopher.hpp"
#include <vector>

class Table
{
public:
	Table(int amount);

private:
    bool isDinner;
    TableSetup setup;
    int amount;
	void preparePhilosophers();
	void prepareForks();

	std::vector<Fork> forks;
	// {
	//    {
	// 		{ 1, 1 },
	// 		{ 2, 2 },
	// 		{ 3, 3 },
	// 		{ 4, 4 },
	// 		{ 5, 5 },
	// 		{ 6, 6 },
	// 		{ 7, 1 },
	// 	 }
	// };


	std::vector<Philosopher> philosophers;
	// {
	//    {
	// 		{ 1, "Austin", setup, forks[0], forks[1] },
	// 		{ 2, "Barnie", setup, forks[1], forks[2] },
	// 		{ 3, "Cedric", setup, forks[2], forks[3] },
	// 		{ 4, "Darren", setup, forks[3], forks[4] },
	// 		{ 5, "Elijah", setup, forks[4], forks[5] },
	// 		{ 6, "Freddy", setup, forks[5], forks[6] },
	// 		{ 7, "George",   setup, forks[6], forks[0] },
	// 	  }
	// };

public:
	void dinnerStart();
	void dinnerStop();
	const std::vector<Philosopher> &getPhilosophers();
	const std::vector<Fork> &getForks();
	const TableSetup &getSetup();
    bool getIsDinner() const;

};
