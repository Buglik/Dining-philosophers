#include "Phiosopher.hpp"
#include <array>
#include <chrono>
#include <iomanip>
#include <thread>
#include <atomic>
#include <iostream>
#include <iomanip>
#include <string>
#include <condition_variable>
#include <mutex>
#include "Random.hpp"


Philosopher::Philosopher(int id, std::string n, TableSetup & s, Fork & l, Fork & r):
    id(id), name(n), setup(s), leftFork(l), rightFork(r), progress(0.0f), state(State::thinking), thread(&Philosopher::run, this)
    {}

Philosopher::~Philosopher()
{
    thread.join();
}    

void Philosopher::run()
{
    setup.talk.wait();
    while(!setup.getStatus())
    {
        think();
        eat();
        // what a beautiful life :)
    }
}

void Philosopher::think()
{
    print(" is thinking ");
    wait();
    state = State::hungry;
}

void Philosopher::eat()
{
    leftFork.ask(id);
    rightFork.ask(id);

    std::scoped_lock lock(rightFork.getMutex(), leftFork.getMutex());

    state = State::eating;
    print(" is eating ");
    wait();
    print(" finished eating ");

    state = State::thinking;
    leftFork.finished();
    rightFork.finished();
}

void Philosopher::wait()
{
    int delayCounter = Random().randomInt(100,150);

    for(int i=0; i<=delayCounter; i++)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        progress = static_cast<float>(i) / static_cast<float>(delayCounter);
    }
    progress = 0.0f;
}


void Philosopher::print(std::string text)
{
    std::ostringstream s1;
    s1 << name << text << std::endl;
}

State Philosopher::getState() const
{
    return state;
}

std::string Philosopher::getStateString() const
{
    switch (state)
    {
    case State::thinking:
        return "thinking";
    case State::hungry:
        return "hungry";
    case State::eating:
        return "eating";          
    default:
        return "no state";
    }
}

std::string Philosopher::getName() const
{
    return name;
}

float Philosopher::getProgress() const
{
    return progress;
}






