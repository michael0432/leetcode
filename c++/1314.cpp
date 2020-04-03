class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
        vector<vector<int>> dp = mat;
        vector<vector<int>> ans = mat;
        
        for (int i = 1; i < mat.size(); i++){
            dp[i][0] = dp[i-1][0] + mat[i][0];
        }
        for (int j = 1; j < mat[0].size(); j++){
            dp[0][j] = dp[0][j - 1] + mat[0][j];
        }
        for (int i = 1; i < mat.size(); i++){
            for (int j = 1; j < mat[0].size(); j++){
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mat[i][j];
            }
        }
        for (int i = 0; i < mat.size(); i++){
            for (int j = 0; j < mat[0].size(); j++){
                int x1 = max(i - K, 0);
                int x2 = min((int)mat.size() - 1, i + K);
                int y1 = max(j - K, 0);
                int y2 = min((int)mat[0].size() - 1, j + K);
                ans[i][j] = dp[x2][y2];
                if(y1 > 0)
                    ans[i][j] -= dp[x2][y1 - 1];
                if(x1 > 0)
                    ans[i][j] -= dp[x1 - 1][y2];
                if(x1 > 0 && y1 > 0)
                    ans[i][j] += dp[x1-1][y1-1];
            }
        }
        return ans;
    }
};