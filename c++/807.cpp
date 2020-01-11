#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowMax(grid.size(),0);
        vector<int> columnMax(grid[0].size(),0);
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[i].size() ; j++){
                if(grid[i][j] > rowMax[i]){
                    rowMax[i] = grid[i][j];
                }
                if(grid[i][j] > columnMax[j]){
                    columnMax[j] = grid[i][j];
                }
            }
        }
        int total_increase = 0;
        for(int i=0 ; i<grid.size() ; i++){
            for(int j=0 ; j<grid[i].size() ; j++){
                int new_height;
                if(rowMax[i] > columnMax[j]){
                    new_height = columnMax[j];
                }
                else{
                    new_height = rowMax[i];
                }
                total_increase += new_height - grid[i][j];
            }
        }
        return total_increase;
    }
};

int main(){
    vector<vector<int>> grid = {{3,0,8,4},{2,4,5,7},{9,2,6,3},{0,3,1,0}};
    Solution s;
    // s.numRescueBoats(people, limit);
    cout << s.maxIncreaseKeepingSkyline(grid) << endl;
}