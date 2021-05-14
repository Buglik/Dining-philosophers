#include "TableSetup.hpp"

bool TableSetup::getStatus()
{
    return status;
}

void TableSetup::setStatus(bool newStatus)
{
    status.exchange(newStatus);
}