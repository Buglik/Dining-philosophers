#pragma once
#include <mutex>
#include <condition_variable>

class Talk
{
private:
    std::mutex mutex;
    std::condition_variable cv;
    bool go = false;

public:
    void wait();
    void letEveryoneKnow();
};
