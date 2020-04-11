class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        vector<int> sums(10001,0);
        vector<int> dp(10003,0);
        for (int i = 0; i < nums.size(); i++){
            sums[nums[i]] += nums[i];
        }
        for (int i = 2; i < 10003; i++){
            dp[i] = max(dp[i-1], dp[i - 2] + sums[i]);
        }
        return dp[10002];
    }
};