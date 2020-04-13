class Solution {
public:
    string longestPalindrome(string s) {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int maxlen = 1, startidx = 0;
        for (int len = 1; len <= s.size(); len++){
            for (int i = 0; i + len <= s.size(); i++){
                int j = i + len - 1;
                if(len == 1)
                    dp[i][j] = true;
                else if(len == 2){
                    if(s[i] == s[j]){
                        dp[i][j] = (s[i] == s[j]);
                        if(len > maxlen){
                            maxlen = len;
                            startidx = i;
                        }
                    }   
                } 
                else{
                    if(s[i] == s[j] && dp[i+1][j-1]){
                        dp[i][j] = true;
                        if(len > maxlen){
                            maxlen = len;
                            startidx = i;
                        }
                    }
                    else
                        dp[i][j] = false;
                }
            }
        }
        string output = "";
        for (int i = 0; i < maxlen; i++){
            output += s[startidx + i];
        }
        return output;
    }
};