#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int, int> m;
    int tribonacci(int n) {
        if(m.count(n) != 0) return m[n];
        else{
            if(n == 0) return 0;
            if(n == 1) return 1;
            if(n == 2) return 1;
            int ans = tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
            m[n] = ans;
            return ans;
        }
        
    }
};