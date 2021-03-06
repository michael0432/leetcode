class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(K+1, vector<int>(N+1));
        for (int j = 1; j <= N; j++){
            dp[1][j] = j;
        }
        for (int i = 2; i <= K; i++){
            for (int j = 1; j <= N; j++){
                dp[i][j] = j;

                int left = 1, right = j;
                while(left < right){
                    int mid = (left + right) / 2;
                    if(dp[i-1][mid-1] < dp[i][j-mid])
                        left = mid + 1;
                    else
                        right = mid;
                }

                
                    
                dp[i][j] = min(dp[i][j], max(dp[i - 1][right - 1], dp[i][j - right])+1);
                
            }
        }
        return dp[K][N];
    }
};