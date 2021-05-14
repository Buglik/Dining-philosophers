#pragma once
#include <atomic>
#include "Talk.hpp"

class TableSetup
{
private:
    std::atomic<bool> status { false };
public:
    Talk talk;
    bool getStatus();
    void setStatus(bool newStatus);
};