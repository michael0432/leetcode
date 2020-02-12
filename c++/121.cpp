#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_v = INT_MAX;
        int max_profit = 0;
        for(int i=0 ; i<prices.size() ; i++){
            min_v = min(prices[i], min_v);
            max_profit = max(prices[i]-min_v, max_profit);
        }
        return max_profit;
    }
};