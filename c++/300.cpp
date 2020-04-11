#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> dp = {1};
        int maxout = 0;
        for(int i=1 ; i<nums.size() ; i++){
            int maxi = 0;
            for(int j=0 ; j<dp.size() ; j++){
                if(nums[i] > nums[j]){
                    maxi = max(maxi, dp[j]);
                }
            }
            dp.push_back(maxi+1);
            maxout = max(maxi+1, maxout);
        }
        return maxout;
    }
};

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int maxout = 1;
        vector<int> dp(nums.size(), 1);
        for (int i = 0; i < dp.size(); i++){
            for (int j = i - 1; j >= 0;j--){
                if(nums[j] < nums[i])
                    dp[i] = max(dp[i], dp[j] + 1);
                maxout = max(dp[i], maxout);
            }
        }
        return maxout;
    }
};