#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int count = 0;
    vector<vector<bool>> map = {};
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0) return 0;
        // zero padding
        vector<char> v(grid[0].size(),'0');
        grid.insert(grid.begin(),v);
        grid.push_back(v);
        for(int i=0 ; i<grid.size() ; i++){
            grid[i].insert(grid[i].begin(),'0');
            grid[i].push_back('0');
        }
        
        // map
        for(int i=0 ; i<grid.size() ; i++){
            map.push_back(vector<bool>(grid[0].size(),false));
        }
        
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[0].size() ; j++){
                
                if(map[i][j] == false && grid[i][j] != '0'){
                    
                    findIslands(i,j,grid);
                    count += 1;
                    map[i][j] = true;
                }
            }
        }
        return count;
    }

    void findIslands(int x, int y, vector<vector<char>>& grid){
        map[x][y] = true;
        if(isValid(x,y-1,grid) && isValid(x,y+1,grid) && isValid(x-1,y,grid) && isValid(x+1,y,grid)){
            
            return;
        }
        else{
            if(!isValid(x,y-1,grid)) findIslands(x,y-1,grid);
            if(!isValid(x,y+1,grid)) findIslands(x,y+1,grid);
            if(!isValid(x-1,y,grid)) findIslands(x-1,y,grid);
            if(!isValid(x+1,y,grid)) findIslands(x+1,y,grid);
        }
        return;
    }

    bool isValid(int x, int y, vector<vector<char>>& grid){
        if(grid[x][y] == '0' || map[x][y] == true) return true;
        else return false;
    }
};

int main(){
    vector<vector<char>> grid = {{'1','1','0','0','0'},{'1','1','0','0','0'},{'0','0','1','0','0'},{'0','0','0','1','1'}};
    Solution s;
    cout << s.numIslands(grid) << endl;

}