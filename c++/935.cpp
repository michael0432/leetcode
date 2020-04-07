class Solution {
public:

    int knightDialer(int N) {
        vector<vector<int>> dir = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        vector<vector<long long>> dp(N, vector<long long>(10, 0));
        long long cnt = 0;
        for (int i = 0; i < 10;i++){
            dp[0][i] = 1;
        }
        for (int i = 1; i < N;i++){
            for (int j = 0; j < 10; j++){
                for (int k = 0; k < dir[j].size(); k++){
                    dp[i][dir[j][k]] += dp[i-1][j];
                    dp[i][dir[j][k]] %= 1000000007;
                }
            }
        }
        
        for (int i = 0; i < 10; i++){
            cnt += dp[N - 1][i];
        }
        return cnt % 1000000007;
    }
    
};