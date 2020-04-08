class Solution {
public:
    int numTilings(int N) {
        vector<vector<long long>> dp(max(3,N + 1), vector<long long>(3, 0));
        int mod = 1000000007;
        dp[1][0] = 1;
        dp[2][0] = 2;
        dp[2][1] = 1;
        dp[2][2] = 1;
        for (int i = 3; i <= N; i++){
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 2][0]) % mod;
            dp[i][1] = (dp[i - 2][0] + dp[i - 1][2]) % mod;
            dp[i][2] = (dp[i - 2][0] + dp[i - 1][1]) % mod;
        }
        return dp[N][0];
    }
};