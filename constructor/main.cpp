#include <memory>
#include <iostream>

class A
{
public:
    A(int n):n_(n){};
    void print()
    {
        std::cout <<n_ << std::endl;
    };
    int n_;
};

class man
{
public:
    man(int age):age_(age){};
    int age_;
    A a = A(age_);
};

int main()
{
    std::shared_ptr<man> manPtr;
    if (!manPtr)
    {
        std::cout << "111" << std::endl; // ok
    }

    manPtr = std::make_shared<man>(333);
    if (!manPtr)
    {
        std::cout << "222" << std::endl; // not
    }

    manPtr->a.print();

}