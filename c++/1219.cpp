class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int dfs(vector<vector<int>>& grid, pair<int,int> pos){
        if(grid[pos.first][pos.second] == 0)
            return 0;
        int sum = 0;
        int origin = grid[pos.first][pos.second];
        grid[pos.first][pos.second] = 0;
        for (int i = 0; i < dir.size(); i++){
            pair<int, int> new_pos = {pos.first + dir[i][0], pos.second + dir[i][1]};
            if(new_pos.first >= 0 && new_pos.first < grid.size() && new_pos.second >= 0 && new_pos.second < grid[0].size()){
                sum = max(sum, dfs(grid, new_pos));
            }
        }
        grid[pos.first][pos.second] = origin;
        return sum + origin;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int maxi = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                maxi = max(dfs(grid, {i, j}), maxi);
            }
        }
        return maxi;
    }
};