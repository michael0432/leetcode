class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unordered_map<int,bool> row;
        unordered_map<int,bool> col;
        int ans = 0, total_com = 0;
        for(int i=0 ; i<grid.size() ; i++){
            int cnt = 0;
            for(int j=0 ; j<grid[i].size() ; j++){
                if(grid[i][j] == 1) cnt++;
            }
            if(cnt <= 1) row[i] = true;
        }
        for(int i=0 ; i<grid[0].size() ; i++){
            int cnt = 0;
            for(int j=0 ; j<grid.size() ; j++){
                if(grid[j][i] == 1) cnt++;
            }
            if(cnt <= 1) col[i] = true;
        }
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[i].size() ; j++){
                if(grid[i][j] == 1 && row.count(i) && col.count(j)) ans++;
                if(grid[i][j] == 1) total_com ++;
            }
        }
        return total_com - ans;
    }
};