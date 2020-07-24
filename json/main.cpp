#include <iostream>
#include <stdexcept>
#include <string>
#include <memory>

#include "json.hpp"

void test()
{
    nlohmann::json test;
    test["publicKeys"] = nlohmann::json::array({{"one", 1}, {"two", 2}});
    test["publicKeys2"] = nlohmann::json::array({nlohmann::json::object({ {"one", 1}, {"two", 2} })});

    std::cout << test.dump() << std::endl;

    nlohmann::json deltaChange;
    deltaChange["publicKeys"] =
        nlohmann::json::array({ nlohmann::json::object({ {"keyDescription", "#1"}, {"keyValue", "ssh-rsa AAAAB3NzaC1yc2EAAAADAQAk ute@SC5G-eNB-190"} }),
                                nlohmann::json::object({ {"keyDescription", "#2"}, {"keyValue", "ssh-rsa AAAAB3NzaC1yc2EAAAADAQAB ute@SC5G-eNB-190"} }) });

    std::cout << deltaChange.dump() << std::endl << std::endl;

    nlohmann::json deltaChange2;
    deltaChange2["publicKeys"] = nlohmann::json::array({
        nlohmann::json::object({ {"keyDescription", "#1"}, {"keyValue", "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDlT\
BaOJSTmi6mLRj9tHWO4Y2dFtr51cQVJR7uhU+xIVj4DDCvEupBpBbW0KtNjtUoaa9STRv2Eg10SPnlAHNvIfYFF1BBXfeBXN396PJrhs6WtdBoH ut\
e@SC5G-eNB-190"} }),
        nlohmann::json::object({ {"keyDescription", "#2"}, {"keyValue", "ssh-rsa AAAAB3NzaC1yc2EAAAADAQABAAABAQDHk\
Eq9KaSfaaT09rL4rfb5fIXYy9Zx5IvPPtlNxFxb3TC28k0Xhl+AVnkhSilAlNQAugULWylSHR3HfmoUyaUwLJCwr6ytq/P/U5upWA/Zms0IgO32j u\
te@SC5G-eNB-190"} }) });
    std::cout << deltaChange2.dump() << std::endl;
}
int main()
{
    test();

    return 0;
}
