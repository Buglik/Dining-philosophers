#pragma once
#include <thread>
#include <iostream>
#include <atomic>
#include <string>
#include "State.hpp"
#include "TableSetup.hpp"
#include "Fork.hpp"

class Philosopher
{
private:
    int id;
    std::string name;
    TableSetup &setup;
    Fork *leftFork;
    Fork *rightFork;
    std::thread thread;
    std::atomic<float> progress;
    std::atomic<State> state;
    float speedRatio;

public:
    Philosopher(int id, std::string n, TableSetup &s, Fork *l, Fork *r, float speedRatio);
    ~Philosopher();

    void run();
    void print(std::string text);
    void eat();
    void wait();
    void think();
    float getProgress() const;
    State getState() const;
    std::string getName() const;
    std::string getStateString() const;
};
