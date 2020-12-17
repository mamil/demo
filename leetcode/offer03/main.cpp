#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        vector<int> flags;
        flags.resize(100000);
        for(auto i : nums)
        {
            ++flags[i];
            if(flags[i] >= 2)
            {
                return i;
            }
        }
        return -1;
    }
};

int main()
{
    vector<int> nums{2, 3, 1, 0, 2, 5, 3};

    Solution s;
    auto res = s.findRepeatNumber(nums);

    std::cout <<res <<std::endl;

    return 0;
}