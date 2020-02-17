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