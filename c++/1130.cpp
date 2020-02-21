#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(),vector<int>(arr.size(),-1));
        return dfs(dp, arr, 0, arr.size()-1);
    }
    int dfs(vector<vector<int>>& dp,vector<int>& arr, int sid, int eid){
        int min_sum = INT_MAX;
        if(sid >= eid) return 0;
        if(dp[sid][eid] != -1) return dp[sid][eid];
        for(int i=sid+1 ; i<=eid ; i++){
            min_sum = min(min_sum, dfs(dp,arr,sid,i-1)+dfs(dp,arr,i,eid)+getmax(arr,sid,i-1)*getmax(arr,i,eid));
        }
        dp[sid][eid] = min_sum;
        return min_sum;
    }
    int getmax(vector<int>& arr, int sid, int eid){
        int maxi = INT_MIN;
        for(int i=sid ; i<=eid ; i++){
            maxi = max(maxi, arr[i]);
        }
        return maxi;
    }
};