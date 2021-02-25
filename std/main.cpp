#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using std::string;
using std::vector;

void string_test()
{
    std::cout << "##################################" << std::endl;


    std::string param = R"(ssh-rsa AAAAB3NuaC1yc2EAA
AADAQABAAABAQDlTiCJOvfAUKWOcADiJ5gSVYIYv7Wu9CV
opc6eOd+78SP+ESudcx4nKZtsL78cYJ+CssnA0Tkgw+dU
AuFqEv07prcVv4rcfFGg0S1ZAZ799Tx516ZWVFZyjE734W
hdURQIUekxnpSBaOJSTmi6mLRj9tHWO4Y2dFtr91cQVJR7
uhU+xIVj4DDCvEupBpBbW0KtNlhUoaa9STRv2Eg10SPnlA
HNvIfYoF1BBXfeBXy396PJs6WtdBor9 nihao@mail.com)";

    param += "111111111";

    std::cout << param << std::endl << std::endl;

    // Normal string
    string str1 = "Sample.\nmultiline.\ncontent.\n" ;

    // Raw string
    string str2 = R"(Sample.\nmultiline.\ncontent.\n)";

    // Output
    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;
}

void vector_test()
{
    std::cout << "##################################vector_test" << std::endl;
    vector<int> v1;
    std::cout << "capacity:" << v1.capacity() << ", max_size:" << v1.max_size() << std::endl; // capacity:0, max_size:4611686018427387903
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    std::sort(v1.begin(), v1.end(), std::greater<int>());

    std::cout << v1.front() << "~" << v1.back() << " reverted" << std::endl; // 3~1 reverted
    v1.front() = 1;
    v1.back() = 3;

    for (auto i : v1)
    {
        std::cout << i << std::endl; // 1 2 3
    }

    std::cout << std::endl;

    for (auto it = v1.begin(); it != v1.end();) // 最好把++it 移动到内部控制，不然erase，insert之后，很容易多移动，少移动
    {
        if(*it == 3)
        {
            it = v1.erase(it); // 迭代器失效，返回删除之后的元素
            continue; // 如果不continue，又会 ++ ，会跳过一个元素
        }
        else if (*it == 2)
        {
            *it = -1; // 改内容
                    // (gdb) p *it
                    // $7 = (int &) @0x60d014: 2
                    // *it 是一个引用
            ++it;
        }
        else if (*it == 1)
        {
            it = v1.insert(it, 0);
            it += 2; // 现在是-1,0,1 , it指向0，需要+2才能到1之后，不然会一直insert
        }
    }
    for (auto i : v1)
    {
        std::cout << i << std::endl; // 0 -1 1
    }

    auto it = v1.begin();
    v1.reserve(10); // 触发空间重新分配
    if (it != v1.begin())
    {
        std::cout << "moved!" << std::endl; // moved!
    }

    v1.assign(2, 9); // 清空旧的，添加新的
    for (auto i : v1)
    {
        std::cout << i << std::endl; // 9 9
    }

    vector<int> v2;
    v2.assign(3,7);
    auto it1 = v1.begin();
    auto it2 = v2.begin();
    std::cout << "v1:" << *it1 << ", v2:" << *it2 << std::endl; // v1:9, v2:7
    v1.swap(v2);
    std::cout << "v1:" << *it1 << ", v2:" << *it2 << std::endl; // v1:9, v2:7 ,指向的位置不变，迭代器还是有效
    std::cout << "v1:" << *v1.begin() << ", v2:" << *v2.begin() << std::endl; // v1:7, v2:9 ，但是名字上容易有歧义，现在v1，v2内容互换，
                                                                            // 看起来是v1的迭代器内容为v2里面的。swap之后还是重新初始化吧

    it = v1.begin();
    v1.clear(); // 清空数据，但是不一定会重新分配空间
    if (it == v1.begin())
    {
        std::cout << "cleared!" << std::endl; // cleared!
    }
}

void map_test()
{
    std::cout << "################################## map_test" << std::endl;

    std::map<int, int> in;
    in[1]=2;
    auto it = in.insert({1,999}); // 插入会失败,返回现有的键值对
    if (it.second == false)
    {
        std::cout << "insert fail, first:" << it.first->first << ", " << it.first->second << std::endl; // insert fail, first:1, 2
    }
    std::cout << "in[1]:" << in[1] << std::endl; // in[1]:2

    std::map<int,std::map<int, int>> test;
    test[3]=in;
    for (auto it : test)
    {
        std::cout << it.first << std::endl;; // 3
        for(auto it2: it.second)
        {
            std::cout << it2.first << ":" << it2.second << std::endl; // 1:2
        }
    }

    test.clear(); // 会清空test，in不受影响

    in[2] = 3;
    in[3] = 4;

    auto itf = in.find(3);
    if (itf != in.end())
    {
        std::cout << "find first:" << itf->first << ", second:" << itf->second << std::endl; // find first:3, second:4
        in.insert({4,5});
        std::cout << "find first:" << itf->first << ", second:" << itf->second << std::endl; // find first:3, second:4
        std::cout << "in[4]:" << in[4] <<std::endl; // in[4]:5
    }

}
int main() {
   string_test();
   vector_test();
   map_test();
   return 0;
}
