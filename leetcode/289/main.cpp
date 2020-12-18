#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum = 0;
        for(auto i: t)
        {
            sum += i;
        }
        for(auto i: s)
        {
            sum -= i;
        }
        return sum;
    }
};

int main()
{
    string s = "a";
    string t = "aa";
    Solution ss;
    auto c = ss.findTheDifference(s,t);
    std::cout << c<< std::endl;
    return 0;
}