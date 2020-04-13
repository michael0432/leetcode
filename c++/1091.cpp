class Solution {
public:
    vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}, {1,1}, {-1,-1}, {-1,1}, {1,-1}};

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1)
            return -1;
        queue<pair<int,int>> q;
        unordered_set<int> m;
        q.push({0, 0});
        int level = 0;

        while(!q.empty()){
            int size = q.size();
            
            for (int i = 0; i < size; i++){
                pair<int, int> qf = q.front();
                m.insert(qf.first * n + qf.second);
                if(qf.first == n-1 && qf.second == n-1){
                    return level + 1;
                }
                for (int d = 0; d < 8; d++){
                    pair<int, int> new_pos = {qf.first + dir[d][0], qf.second + dir[d][1]};
                    if(new_pos.first >= 0 && new_pos.first < grid.size() && new_pos.second >= 0 && new_pos.second < grid[0].size()){
                        
                        if(m.count(new_pos.first * n + new_pos.second) == 0 && grid[new_pos.first][new_pos.second] == 0){
                            q.push(new_pos);
                        }
                    }
                }
                q.pop();
            }
            level++;
        }
        return -1;
    }
};