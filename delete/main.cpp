#include <memory>
#include <iostream>

class Man
{
public:
    Man() = default;
    // ~Man() = delete; // error: use of deleted function ‘Man::~Man()’

    int age;
};

int main()
{
    {
        auto man = std::make_shared<Man>();
    }
}