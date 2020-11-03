#include <memory>
// #include <optional>
#include <iostream>

class man
{
public:
    int age;
};

int main()
{
    std::shared_ptr<man> manPtr;
    if (!manPtr)
    {
        std::cout << "111"; // ok
    }

    manPtr = std::make_shared<man>();
    if (!manPtr)
    {
        std::cout << "222"; // not
    }

    // std::optional<std::shared_ptr<man> > manOpt;

}