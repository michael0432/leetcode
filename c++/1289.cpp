class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr[0].size(), INT_MAX));
        int min_cost = INT_MAX;
        for (int i = 0; i < arr[0].size(); i++){
            dp[0][i] = arr[0][i];
        }
            
        for (int i = 1; i < arr.size(); i++){
            for (int j = 0; j < arr[i].size(); j++){
                for (int k = 0; k < arr[i].size(); k++){
                    if(j != k)
                        dp[i][j] = min(dp[i][j], dp[i - 1][k] + arr[i][j]);
                    if(i == arr.size()-1){
                        min_cost = min(min_cost, dp[i][j]);
                    }
                }   
            } 
        }
        return min_cost;
    }
};