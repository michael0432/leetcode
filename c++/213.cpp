class Solution {
public:

    int solve(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n+2);
        for (int i = 2; i < dp.size(); i++){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i-2]);
        }
        return dp[dp.size() - 1];
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int> front;
        vector<int> back;
        for (int i = 0; i < nums.size(); i++){
            if(i != nums.size()-1)
                front.push_back(nums[i]);
            if(i != 0)
                back.push_back(nums[i]);
        }
        return max(solve(front), solve(back));
    }
};