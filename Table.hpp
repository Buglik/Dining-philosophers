#pragma once
#include <array>
#include "TableSetup.hpp"
#include "Fork.hpp"
#include "Phiosopher.hpp"
#include <vector>

class Table
{
public:
	Table(int n, float speed);

private:
	std::atomic<bool> isDinner;
	TableSetup setup;
	int amount;
	float speedRatio;

	std::vector<Fork *> forksV;
	std::vector<Philosopher *> philosophersV;

public:
	void prepareForks();
	void preparePhilosophers();
	void dinnerStart();
	void dinnerStop();
	std::vector<Philosopher *> &getPhilosophers();
	std::vector<Fork *> &getForks();
	const TableSetup &getSetup();
	bool getIsDinner() const;
};
