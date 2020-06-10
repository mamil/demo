#include <arpa/inet.h>
#include <string>
#include <iostream>

void check()
{
    std::string ipAddr4 = "192.168.0.1";
    std::string ipAddr4wa = "192.168.0.0.1";

    struct sockaddr_in sa;
    int ret = 0;
    ret = inet_pton(AF_INET, ipAddr4.c_str(), &(sa.sin_addr));
    std::cout << ret << std::endl;

    ret = inet_pton(AF_INET, ipAddr4wa.c_str(), &(sa.sin_addr));
    std::cout << ret << std::endl;

    std::string ipAddr6 = "2001:0db8:3c4d:0015:0000:0000:1a2f:1a2b";
    std::string ipAddr6wa = "192.168.0.0.1";

    ret = inet_pton(AF_INET6, ipAddr6.c_str(), &(sa.sin_addr));
    std::cout << ret << std::endl;

    ret = inet_pton(AF_INET6, ipAddr6wa.c_str(), &(sa.sin_addr));
    std::cout << ret << std::endl;

    ret = inet_pton(AF_INET, ipAddr6.c_str(), &(sa.sin_addr)); // 会产生一个崩溃，有时间可以看看，in free () from /lib64/libc.so.6
    std::cout << ret << std::endl;
}
// 1
// 0
// 1
// 0
// 0

int main() {
   check();
   return 0;
}
