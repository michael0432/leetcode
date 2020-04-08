class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1, INT_MAX));
        int sum = 0;
        dp[0][0] = 0;
        for (int i = 1; i <= s1.size(); i++){
            sum += s1[i-1];
            dp[i][0] = sum;
        }
        sum = 0;
        for (int i = 1; i <= s2.size(); i++){
            sum += s2[i-1];
            dp[0][i] = sum;
        }
        for (int i = 1; i <= s1.size(); i++){
            for (int j = 1; j <= s2.size(); j++){
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i - 1][j] + s1[i-1], dp[i][j - 1] + s2[j-1]);
            }
        }
        return dp[s1.size()][s2.size()];
    }
};