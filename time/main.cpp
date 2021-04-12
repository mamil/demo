#include <chrono>
#include <iostream>

int main()
{
    unsigned long time = std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()).count();
    std::cout << time << std::endl;;
    return 0;
}