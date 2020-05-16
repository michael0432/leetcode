class Solution {
public:
    int longestPalindromeSubseq(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
        for (int len = 1; len <= s.size(); len++){
            for (int i = 0; i+len-1 < s.size(); i++){
                int j = i + len - 1;
                if(i == j){
                    dp[i][j] = 1;
                    continue;
                }
                if(s[i] == s[j])
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][s.size()-1];
    }
};