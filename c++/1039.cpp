class Solution {
public:

    int minScoreTriangulation(vector<int>& A) {
        vector<vector<int>> dp(A.size(), vector<int>(A.size(), INT_MAX));
        for (int i = 0; i < A.size()-1; i++){
            dp[i][i + 1] = 0;
        }
        for (int d = 2; d < A.size(); d++){
            for (int i = 0; i+d < A.size(); i++){
                int j = i + d;
                for (int k = i + 1; k < j; k++){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + A[i] * A[j] * A[k]);
                }
            }
        }
        return dp[0][A.size()-1];
    }
};