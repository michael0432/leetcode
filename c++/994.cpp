class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh_num = 0, minute = 0;
        //vector<vector<int>> mem(grid.size(), vector<int>(grid[0].size(), 0));
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1)
                    fresh_num++;
                if(grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        if(fresh_num == 0)
            return 0;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                //cout << minute << q.front().first << q.front().second << endl;
                for (int d = 0; d < dir.size(); d++){
                    int r = q.front().first + dir[d][0];
                    int c = q.front().second + dir[d][1];
                    if (r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && grid[r][c] == 1){
                        fresh_num--;
                        if(fresh_num == 0)
                            return minute+1;
                        grid[r][c] = 2;
                        q.push({r, c});
                    }
                }
                q.pop();
            }
            minute++;
        }
        if(fresh_num == 0)
            return minute;
        return -1;
    }
};