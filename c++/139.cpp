#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string ,bool> m;
        vector<int> dp(s.size(),-1);
        for(int i=0 ; i<wordDict.size() ; i++){
            m[wordDict[i]] = true;
        }
        return breakw(s, 0 , s.size()-1, m, dp);
    }
    bool breakw(string s, int sid , int eid, unordered_map<string ,bool>& m, vector<int>& dp){
        string tmp_s = "";
        if(sid > eid) return true;
        if(dp[sid] != -1) return dp[sid];
        for(int i=sid+1 ; i<=eid ; i++){
            tmp_s += s[i];
            if(m.count(tmp_s) != 0){
                bool ans = breakw(s, i, eid, m, dp);
                if(ans) return true;
                dp[i] = false; 
            }
        }
        return false;
    }
};