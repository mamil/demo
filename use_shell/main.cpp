#include <cstdio>
#include <string>
#include <string.h>
#include <iostream>

int main()
{
    const int SIZE = 64;
    const int MAX_RESPONSE_SIZE = 65535;
    char charBuff[SIZE];
    int bytesRead = 0;
    int closeResult;
    std::string result_;
    std::string cmd_ = "ls -al";

    if (system(nullptr) == 0)
    {
        std::cout << "shell not available" << std::endl;
        return 1;
    }

    auto cmdOut = popen(cmd_.c_str(), "r");
    if (cmdOut == nullptr)
    {
        std::cout << "popen error" << std::endl;
        return 1;
    }

    while (fgets(charBuff, SIZE, cmdOut) != nullptr)
    {
        if (bytesRead + strlen(charBuff) >= MAX_RESPONSE_SIZE)
        {
            result_.append(charBuff, MAX_RESPONSE_SIZE - bytesRead);
            break;
        }
        else
        {
            result_.append(charBuff);
        }

        bytesRead += strlen(charBuff);
    }

    closeResult = pclose(cmdOut);

    std::cout << "bytesRead=" << bytesRead << std::endl;
    std::cout << "closeResult=" << closeResult << std::endl;
    std::cout << "WEXITSTATUS(closeResult)=" << WEXITSTATUS(closeResult) << std::endl;
    std::cout << "result=" << result_ << std::endl;

    return 0;
}