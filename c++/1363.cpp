class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        vector<vector<string>> dp(digits.size()+1, vector<string>(3, ""));
        for (int i = 0; i < digits.size(); i++){
            if(digits[i] % 3 == 0){
                dp[i][0] = dp[i - 1][0] + to_string(digits[i]);
                dp[i][1] = dp[i - 1][1] + to_string(digits[i]);
                dp[i][2] = dp[i - 1][2] + to_string(digits[i]);
            }
            else if(digits[i] % 3 == 1){
                dp[i][0] = dp[i - 1][2] + to_string(digits[i]);
                dp[i][1] = dp[i - 1][0] + to_string(digits[i]);
                dp[i][2] = dp[i - 1][1] + to_string(digits[i]);
            }
            else{
                dp[i][0] = dp[i - 1][1] + to_string(digits[i]);
                dp[i][1] = dp[i - 1][2] + to_string(digits[i]);
                dp[i][2] = dp[i - 1][0] + to_string(digits[i]);
            }
        }
        string s = dp[dp.size() - 1][0];
        sort(s.begin(), s.end(), greater<char>());
    }
};