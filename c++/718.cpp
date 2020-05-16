class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> dp(A.size()+1, vector<int>(B.size()+1, 0));
        int output = 0;
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < B.size(); j++){
                if(A[i] == B[j]){
                    //cout << i << j << endl;
                    dp[i+1][j+1] = dp[i][j] + 1;
                    output = max(output, dp[i + 1][j + 1]);
                }
                else{
                    dp[i+1][j+1] = 0;
                }
            }
        }
        return output;
    }
};