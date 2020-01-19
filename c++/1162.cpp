#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    
    int maxDistance(vector<vector<int>>& grid) {
        queue<vector<int>> q;
    
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[i].size() ; j++){
                if(grid[i][j] == 1) q.push({i,j});
            }
        }
        if(q.size() == 0 || q.size() == grid.size()*grid[0].size()) return -1;
        int cnt = 0;
        while(q.size() > 0){
            int size = q.size();
            
            while(size > 0){
                size -= 1;
                vector<int> v = q.front();
                if(v[0]-1 >= 0 && grid[v[0]-1][v[1]] == 0){
                    grid[v[0]-1][v[1]] = 1;
                    q.push({v[0]-1,v[1]});
                }
                if(v[0]+1 < grid.size() && grid[v[0]+1][v[1]] == 0){
                    grid[v[0]+1][v[1]] = 1;
                    q.push({v[0]+1,v[1]});
                }
                if(v[1]-1 >= 0 && grid[v[0]][v[1]-1] == 0){
                    grid[v[0]][v[1]-1] = 1;
                    q.push({v[0],v[1]-1});
                }
                if(v[1]+1 < grid.size() && grid[v[0]][v[1]+1] == 0){
                    grid[v[0]][v[1]+1] = 1;
                    q.push({v[0],v[1]+1});
                } 
                q.pop();
            }
            cnt += 1;
        }
        return cnt-1;
    }
};


int main(){
    vector<vector<int>> grid = {{1,0,1},{0,0,0},{1,0,1}};
    Solution s;
    cout << s.maxDistance(grid) << endl;
}