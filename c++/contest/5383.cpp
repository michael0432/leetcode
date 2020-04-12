class Solution {
public:
    int numOfWays(int n) {
        int mod = 1000000007;
        if(n == 1)
            return 12;
        vector<vector<int>> v = {{1, 2, 1}, {1, 2, 3}, {1, 3, 1}, {1, 3, 2}, {2, 1, 2}, {2, 1, 3}, {2, 3, 1}, {2, 3, 2}, {3, 1, 2}, {3, 1, 3}, {3, 2, 1}, {3, 2, 3}};
        unordered_map<int, vector<int>> m;
        vector<long long> v2(12, 1);
        for (int i = 0; i < v.size(); i++){
            for (int j = i+1; j < v.size(); j++){
                if(v[i][0] != v[j][0] && v[i][1] != v[j][1] && v[i][2] != v[j][2]){
                    m[i].push_back(j);
                    m[j].push_back(i);
                }
            }
        }
        
        for (int i = 2; i <= n; i++){
            vector<long long> tmp(12,0);
            for (int j = 0; j < 12; j++){
                for(auto x: m[j]){
                    tmp[x] += v2[j] % mod;
                }   
            }
            v2 = tmp;
        }
        long long output = 0;
        
        for(long long t: v2)
            output += t % mod;
        return output % mod;
    }
};