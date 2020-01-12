#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if(nums.size() == 0){
            return {};
        }
        vector<int> dp(1,1);
        vector<vector<int>> divide_num(nums.size());
        sort(nums.begin(),nums.end(),greater<int>());
        divide_num[0].push_back(nums[0]);
        for(int i=1 ; i<nums.size() ; i++){
            int value = 1;
            for(int j=0 ; j<i ; j++){
                if(nums[j] % nums[i] == 0){
                    if((dp[j]+1) > value){
                        value = dp[j]+1;
                        divide_num[i] = divide_num[j];
                        divide_num[i].push_back(nums[i]);
                    }          
                }
            }
            if(divide_num[i].size() == 0){
                divide_num[i].push_back(nums[i]);
            }
            dp.push_back(value);
        }
        
        return divide_num[max_element(dp.begin(), dp.end()) - dp.begin()];
    }
};

int main(){
    vector<int> n = {};
    Solution s;
    vector<int> ans = s.largestDivisibleSubset(n);
    for(int i=0 ; i<ans.size() ; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    //cout << s.largestDivisibleSubset(n) << endl;;
}