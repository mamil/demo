// #include <boost/range/algorithm/find_if.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

class Data
{
public:
    Data(int num): num_(num){};
    int num_;
};

int main()
{
    std::vector<std::shared_ptr<Data> > data;
    for (int i = 0; i < 10 ; ++i)
    {
        data.push_back(std::make_shared<Data>(i));
    }

    int to_find = 5;
    auto it = std::find_if(data.begin(), data.end(), [to_find](std::shared_ptr<Data> data){ return data->num_ == to_find; });

    if (it != data.end())
    {
        std::cout << "find it: " << (*it)->num_ << std::endl;
    }

    std::shared_ptr<Data> test = *it;
    std::cout << "base: " << test->num_ << std::endl;

    return 0;
}