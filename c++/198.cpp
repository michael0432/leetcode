class Solution {
public:
    int rob(vector<int>& nums) {
        nums.insert(nums.begin(), 0);
        nums.insert(nums.begin(), 0);
        vector<int> dp(nums.size());
        for (int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-1], dp[i - 2] + nums[i]);
        }
        return dp[dp.size() - 1];
    }
};