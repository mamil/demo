#include <boost/optional/optional.hpp>
#include <iostream>

int main()
{
    boost::optional<int> n;
    if (!n)
    {
        std::cout << "11" <<std::endl; // 11
    }

    n = 15;
    std::cout << n.get() <<std::endl; // 15
}