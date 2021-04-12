#include <memory>
#include <vector>
#include <iostream>

std::vector<int> test()
{
    std::vector<int> vec = {1,1,1,1,1,1,1,1};
    return std::move(vec);
}

int main()
{
    auto vec = test();
    return 0;
}