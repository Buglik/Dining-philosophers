#pragma once
#include <mutex>
#include <atomic>
#include "Talk.hpp"

class Fork
{
private:
    int id;
    int owner;
    std::atomic<bool> isDirty {false};
    std::mutex mutex;
    Talk talk;

public:
    Fork(int forkId, int ownerId);
    void ask(int ownerId);
    void finished();

    std::mutex& getMutex()
    {
        return mutex;
    }

    int getId()
    {
        return id;
    }

    int getOwner() const;


};
