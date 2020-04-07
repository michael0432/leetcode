class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& satisfaction, int idx, int num){
        if(idx >= satisfaction.size())
            return 0;
        if(dp[idx][num] != -1)
            return dp[idx][num];
        int dothis = solve(satisfaction, idx + 1, num + 1) + satisfaction[idx] * num;
        int notdothis = solve(satisfaction, idx + 1, num);
        dp[idx][num] = max(dothis, notdothis);
        return max(dothis, notdothis);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        dp.resize(satisfaction.size()+1, vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 1);
    }
};

class Solution {
public:
    vector<vector<int>> dp;
    int solve(vector<int>& satisfaction, int idx, int num){
        if(idx >= satisfaction.size())
            return 0;
        if(dp[idx][num] != -1)
            return dp[idx][num];
        int dothis = solve(satisfaction, idx + 1, num + 1) + satisfaction[idx] * num;
        int notdothis = solve(satisfaction, idx + 1, num);
        dp[idx][num] = max(dothis, notdothis);
        return max(dothis, notdothis);
    }

    int maxSatisfaction(vector<int>& satisfaction) {
        dp.resize(satisfaction.size()+1, vector<int>(satisfaction.size()+1,-1));
        sort(satisfaction.begin(), satisfaction.end());
        return solve(satisfaction, 0, 1);
    }
};