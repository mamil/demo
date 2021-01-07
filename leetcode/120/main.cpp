#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>
#include <vector>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        for (int i = triangle.size() -2; i >= 0; --i)
        {
            for (int j = 0; j < triangle[i].size(); ++j)
            {
                triangle[i][j] += std::min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

int main()
{
    vector<vector<int>> t = {{2},{3,4}, {6,5,7}, {4,1,8,3}};
    for (auto it : t)
    {
        for (auto it2 : it)
        {
            std::cout << it2 << " ";
        }
        std::cout << std::endl;
    }

    Solution s;
    auto res = s.minimumTotal(t);
    std::cout << res<< std::endl;

    vector<vector<int>> t2 = {{-1},{-2,-3}};
    for (auto it : t2)
    {
        for (auto it2 : it)
        {
            std::cout << it2 << " ";
        }
        std::cout << std::endl;
    }

    res = s.minimumTotal(t2);
    std::cout << res<< std::endl;

    return 0;
}