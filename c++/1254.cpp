class Solution {
public:

    int closedIsland(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int total_island = 0;
        int island = 0;
        vector<vector<bool>> mem(grid.size(),vector<bool>(grid[0].size(),false));
        vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[i].size() ; j++){
                if(grid[i][j] == 0 && !mem[i][j]){
                    q.push({i,j});
                    bool flag = false;
                    while(!q.empty()){
                        if(!mem[q.front().first][q.front().second]){
                            for(auto d : dir){
                                int x = q.front().first + d[0], y = q.front().second + d[1];
                                if(min(x,y) >= 0 && x < grid.size() && y < grid[0].size()){
                                    if(grid[x][y] == 0) q.push({x,y});
                                }
                                else{
                                    flag = true;
                                }
                            }   
                        }
                        
                        mem[q.front().first][q.front().second] = true;
                        q.pop();
                    }
                    total_island++;
                    if(flag) island++;
                }
            }
        }
        //cout << total_island << island << endl;
        return total_island-island;
    }
};