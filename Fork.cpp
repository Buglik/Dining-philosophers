#include "Fork.hpp"

Fork::Fork(int forkId, int ownerId) :
    id(forkId), owner(ownerId), isDirty(true)
    {}

void Fork::ask(int ownerId)
{
    while(owner != ownerId)
    {
        if(isDirty)
        {
            std::scoped_lock<std::mutex> lock(mutex);
            // cleaning the fork
            isDirty = false;
            owner = ownerId;
        }
        else
        {
            talk.wait();
        }
    }
}

void Fork::finished()
{
    isDirty = true;
    talk.letEveryoneKnow();
}

int Fork::getOwner() const
{
    return owner;
}
