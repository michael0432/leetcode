class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int sum = 0;
        vector<int> dp(arr.size()+1);
        vector<int> output;
        dp[0] = 0;
        for (int i = 0; i < arr.size(); i++){
            dp[i+1] = dp[i] ^ arr[i];
        }
        for (int i = 0; i < queries.size(); i++){
            output.push_back(dp[queries[i][0]] ^ dp[queries[i][1]+1]);
        }
        return output;
    }
};