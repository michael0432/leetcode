class Solution {
public:
    
    vector<int> dp;
    int dfs(vector<int>& stoneValue, int idx){
        
        if(idx >= stoneValue.size()){
            return 0;
        }
        if(dp[idx] != 0)
            return dp[idx];
        int res = INT_MIN, sum = 0;
        for (int i = 0; i < 3 && idx + i < stoneValue.size(); i++){
            sum += stoneValue[idx + i];
            res = max(res, sum - dfs(stoneValue, idx + i + 1));
        }
        dp[idx] = res;
        return res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        
        dp.resize(stoneValue.size(),0);
        int ans = dfs(stoneValue, 0);

        if (ans < 0)
            return "Bob";
        else if (ans == 0)
            return "Tie";
        else
            return "Alice";
    }
};