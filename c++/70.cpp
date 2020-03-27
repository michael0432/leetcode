#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> dp;
    int climbStairs(int n) {
        if(dp.count(n) != 0) return dp[n];
        if(n == 0) return 1;
        if(n == 1) return 1;
        int output = climbStairs(n-1) + climbStairs(n-2);
        dp[n] = output;
        return output;
    }
};



