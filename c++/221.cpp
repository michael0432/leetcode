class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));
        int bigest = 0;
        for (int i = 0; i < dp.size(); i++){
            for (int j = 0; j < dp[i].size(); j++){
                dp[i][j] = matrix[i][j] - '0';
                bigest = max(dp[i][j], bigest);
            }
        }
        
        
        for (int i = 1; i < dp.size(); i++){
            for (int j = 1; j < dp[i].size(); j++){
                if(matrix[i][j] == '1'){
                    if(dp[i-1][j] == dp[i-1][j-1] && dp[i-1][j] == dp[i][j-1]){
                        dp[i][j] = dp[i - 1][j] + 1;
                    }
                    else{
                        dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
                    }
                } 
                bigest = max(dp[i][j], bigest);
            }
        }
        return bigest * bigest;
    }
};