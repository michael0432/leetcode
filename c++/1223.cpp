class Solution {
public:
    
    
    
    int dfs(int n, int last_num, int continue_num, vector<int>& rollMax, vector<vector<vector<int>>>& mem){
        if(n == 0) return 1;
        //cout << n << last_num << continue_num << endl;
        if(last_num != -1 && mem[n][last_num][continue_num] != -1){
            return mem[n][last_num][continue_num];
        }
        
        int ans = 0;
        for(int i=0 ; i<6 ; i++){
            if(i == last_num && continue_num < rollMax[i]){
                ans += dfs(n-1, i, continue_num+1, rollMax, mem) % 1000000007;
            }
            else if(i != last_num){
                ans += dfs(n-1, i, 1, rollMax, mem) % 1000000007;
            }
        }
        //cout << n << last_num << continue_num << endl;
        if(last_num != -1) mem[n][last_num][continue_num] = ans;
        return ans;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> mem(n+1,vector<vector<int>>(6,vector<int>(16,-1)));
        return dfs(n,-1,0,rollMax,mem);
    }
};