#include <array>
#include <mutex>
#include <thread>
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <iomanip>
#include <condition_variable>
#include "Table.hpp"
#include "UI.hpp"

void start()
{
    int n;
    float x;
    std::cout << "Enter number of philosophers" << std::endl;
    std::cin >> n;
    std::cout << "Enter speed ratio (default 1)" << std::endl;
    std::cin >> x;

    Table table(n, x);
    UI ui(table.getPhilosophers(), table, table.getForks());
    table.dinnerStart();
    while (table.getIsDinner())
        ;
}

int main()
{
    start();
    return 0;
}