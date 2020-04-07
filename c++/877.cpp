class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& piles, int sid, int eid){
        if(sid >= eid)
            return piles[sid];
        if(dp[sid][eid] != 0)
            return dp[sid][eid];
        int s1 = piles[sid] - dfs(piles, sid + 1, eid);
        int s2 = piles[eid] - dfs(piles, sid, eid - 1);
        dp[sid][eid] = max(s1, s2);
        return dp[sid][eid];
    }

    bool stoneGame(vector<int>& piles) {
        dp.resize(piles.size(), vector<int>(piles.size(),0));
        if(dfs(piles,0, piles.size()-1) > 0)
            return true;
        else{
            return false;
        }
    }
};