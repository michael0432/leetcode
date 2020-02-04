#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        vector<int> s0 = {0};
        vector<int> s1 = {-prices[0]};
        vector<int> s2 = {INT32_MIN};

        for(int i=1 ; i<prices.size() ; i++){
            s0.push_back(max(s0[i-1], s2[i-1]));
            s1.push_back(max(s0[i-1]-prices[i], s1[i-1]));
            s2.push_back(s1[i-1]+prices[i]);
        }
        return max(s0[s0.size()-1],s2[s2.size()-1]);
    }
};

int main(){
    vector<int> n = {1,2,3,0,2};
    Solution s;
    cout << s.maxProfit(n) << endl;
}