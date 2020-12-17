#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        for (auto it1 = matrix.begin(); it1 != matrix.end(); ++it1)
        {
            for (auto it2 = it1->begin(); it2 != it1->end(); ++it2)
            {
                if (*(it1->begin()) > target)
                {
                    return false;
                }

                if(*it2 == target)
                {
                    return true;
                }
                if(*it2 > target)
                {
                    continue;
                }
            }
        }
        return false;
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