#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>
#include <vector>
#include <cstring>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        string res, now = str;
        for (auto c : now)
        {
            if (c == ' ')
                res += "%20";
            else
                res += c;
        }
        strcpy(str, res.c_str());
	}
};

int main()
{
    char str[] = "we are happy";
    Solution s;
    s.replaceSpace(str, 13);

    std::cout <<str <<std::endl;

    return 0;
}