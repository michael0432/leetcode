class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int cnt = 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),0));
        for (int i = 0; i < matrix.size(); i++){
            if(matrix[i][0] == 1)
                dp[i][0] = 1;
            cnt += dp[i][0];
        }
        for (int i = 1; i < matrix[0].size(); i++){
            if(matrix[0][i] == 1)
                dp[0][i] = 1;
            cnt += dp[0][i];
        }
        
        for (int i = 1; i < matrix.size(); i++){
            for (int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j] == 1) 
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                cnt += dp[i][j];
            }
        }
        return cnt;
    }
};