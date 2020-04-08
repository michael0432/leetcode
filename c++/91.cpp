class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size(), 0);
        if(s[0] == '0')
            return 0;
        dp[0] = 1;
        for (int i = 1; i < s.size(); i++){
            if(s[i] == '0')
                dp[i] = 0;
            else
                dp[i] = dp[i-1];
            string tmp;
            tmp += s[i-1];
            tmp += s[i];
            
            if(stoi(tmp) <= 26 && stoi(tmp) >= 10)
                dp[i] += dp[max(0,i - 2)];
        }
        // for (int i = 0; i < dp.size(); i++)
        //     cout << dp[i] << endl;
        return dp[s.size()-1];
    }
};