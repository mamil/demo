#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        string res;
        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i] == ' ')
            {
                res += "%20";
            }
            else
            {
                res.push_back(s[i]);
            }
        }
        return res;
    }
};

int main()
{
    // vector<int> nums{2, 3, 1, 0, 2, 5, 3};

    // Solution s;
    // auto res = s.findNumberIn2DArray(nums);

    // std::cout <<res <<std::endl;

    return 0;
}