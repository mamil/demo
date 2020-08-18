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
    v1.push_back(4);
    v1.push_back(3);
    v1.push_back(9);
    std::sort(v1.begin(), v1.end(), std::greater<int>());

    for (auto i : v1)
    {
        std::cout << i << std::endl;
    }

    auto v2 = vector<int>();
    for (auto i : v2)
    {
        std::cout << i << std::endl;
    }
}

void map_test()
{
    std::cout << "##################################" << std::endl;

    std::map<int, int> in;
    in[1]=2;
    std::map<int,std::map<int, int>> test;
    test[3]=in;
    for (auto it : test)
    {
        std::cout << it.first << std::endl;;
        for(auto it2: it.second)
        {
            std::cout << it2.first << ":" << it2.second << std::endl;
        }
    }
    test.erase(3);

    auto testit = test.find(3)->second;
    testit.erase(1);

    for (auto it : test)
    {
        std::cout << it.first<< std::endl;;
        for(auto it2: it.second)
        {
            std::cout << it2.first << ":" << it2.second << std::endl;
        }
    }

    test.erase(3);

    for (auto it : test)
    {
        std::cout << it.first<< std::endl;;
        for(auto it2: it.second)
        {
            std::cout << it2.first << ":" << it2.second << std::endl;
        }
    }
    std::cout << "##################################222" << std::endl;


}
int main() {
   string_test();
   vector_test();
   map_test();
   return 0;
}
