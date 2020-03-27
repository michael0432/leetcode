class Solution {
public:

    bool trace(vector<vector<int>>& grid, int dir){
        vector<vector<int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};
        vector<vector<int>> grid_dir_map = {{-1,-1},{0,1},{2,3},{0,2},{1,2},{0,3},{1,3}};
        int x = 0 , y = 0;
        while(x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size()){
            if(dir != grid_dir_map[grid[x][y]][0] && dir != grid_dir_map[grid[x][y]][1]) return false;
            if(x == grid.size()-1 && y == grid[0].size()-1) return true;
            if()
        }
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        
    }
};