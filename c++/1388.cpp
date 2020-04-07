class Solution {
public:

    int solve(vector<int> slices, int target){
        vector<vector<int>> dp(slices.size(),vector<int>(target+1));
        for (int i = 0; i < slices.size(); i++)
            dp[i][0] = 0;
        for (int i = 1; i < slices.size(); i++){
            for (int j = 1; j <= target && j < i/2+1 ; j++){
                if(i == 1)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 2][j - 1] + slices[i]);
            }
        }
        return dp[slices.size() - 1][target];
    }

    int maxSizeSlices(vector<int>& slices) {
        int head = solve(vector<int>(slices.begin(), slices.end() - 1), slices.size() / 3);
        int end = solve(vector<int>(slices.begin()+1, slices.end()), slices.size() / 3);
        return max(head, end);
    }
};