#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>
#include <vector>

using namespace std;

// class Solution {
// public:
//     int Fibonacci(int n) {
//         static vector<int> fib;
//         fib.resize(40);
//         if (fib[2] != 1)
//         {
//             fib[0] = 0;
//             fib[1] = 1;
//             for(int i = 2; i <= 39; ++i)
//             {
//                 fib[i] = fib[i-1] + fib[i-2];
//             }
//         }
//         return fib[n];
//     }
// };

class Solution {
public:
    int Fibonacci(int n) {
        static int fib[40];
        if (fib[2] != 1)
        {
            fib[0] = 0;
            fib[1] = 1;
            for(int i = 2; i <= 39; ++i)
            {
                fib[i] = fib[i-1] + fib[i-2];
            }
        }
        return fib[n];
    }
};

int main()
{
    Solution s;
    auto res = s.Fibonacci(4);

    std::cout <<res <<std::endl;

    return 0;
}