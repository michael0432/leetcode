class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<pair<int,int>> dp(nums.size(), {1,0});
        int maxi = 1, output = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i])
                    dp[i].first = max(dp[i].first, dp[j].first + 1);
            }
            for (int j = i - 1; j >= 0; j--){
                if(nums[j] < nums[i] && dp[j].first == dp[i].first - 1)
                    dp[i].second += dp[j].second;
            }
            if(dp[i].second == 0)
                dp[i].second = 1;
            maxi = max(maxi, dp[i].first);
        }
        
        for (int i = 0; i < dp.size();i++){
            if(dp[i].first == maxi){
                output += dp[i].second;
            }
        }
        return output;
    }
};