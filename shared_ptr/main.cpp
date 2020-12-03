#include <memory>
// #include <optional>
#include <iostream>

class man
{
public:
    int age;
};

std::shared_ptr<man> getNull()
{
    return nullptr;
}

int main()
{
    std::shared_ptr<man> manPtr;
    if (!manPtr)
    {
        std::cout << "111" << std::endl; // ok
    }

    manPtr = std::make_shared<man>();
    if (!manPtr)
    {
        std::cout << "222" << std::endl; // not
    }
    manPtr->age = 10;
    std::cout << manPtr->age << std::endl; // 10

    manPtr.reset(new man);
    std::cout << manPtr->age << std::endl; // 未初始化，看内存里有什么

    auto nu = getNull();
    if (! nu)
    {
        std::cout << "get null" << std::endl; // ok
    }
}