#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp = {text1.length(), vector<int> (text2.length(),0)};
        int n = 0;
        for(int i=0 ; i<text1.length() ; i++){
            if(text1[i] == text2[0]) n = 1;
            dp[i][0] = n;
        }
        n = 0;
        for(int i=0 ; i<text2.length() ; i++){
            if(text2[i] == text1[0]) n = 1;
            dp[0][i] = n;
        }
        for(int i=1 ; i<text1.length() ; i++){
            for(int j=1 ; j<text2.length() ; j++){
                if(text1[i] == text2[j]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.length()-1][text2.length()-1];
    }
};

int main(){
    string text1 = "acedeb";
    string text2 = "abcdeb";
    Solution s;
    cout << s.longestCommonSubsequence(text1, text2) << endl;
}