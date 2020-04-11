class Solution {
public:
    int mergeStones(vector<int>& stones, int K) {
        vector<vector<int>> dp(stones.size(), vector<int>(stones.size(), 0));
        vector<int> sum(stones.size()+1, 0);
        if((stones.size()-1) % (K-1) != 0)
            return -1;
        for (int i = 0; i < stones.size(); i++){
            sum[i + 1] = sum[i] + stones[i];
        }
        for (int len = K; len <= stones.size(); len++){
            for (int i = 0; i + len <= stones.size(); i++){
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k+= K-1)
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                if((j-i) % (K-1) == 0)
                    dp[i][j] += sum[j + 1] - sum[i];
            }
        }
        return dp[0][stones.size() - 1];
    }
};