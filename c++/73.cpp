#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_map<int, bool> row;
        unordered_map<int, bool> column;
        for(int i=0 ; i<matrix.size() ; i++){
            for(int j=0 ; j<matrix[i].size() ; j++){
                if(matrix[i][j] == 0){
                    if(!row.count(i)) row[i] = true;
                    if(!column.count(j)) column[j] = true;
                }
            }
        }
        for(auto it = row.begin() ; it != row.end() ; it++){
            for(int i=0 ; i<matrix[0].size() ; i++){
                matrix[it->first][i] = 0;
            }
        }
        for(auto it = column.begin() ; it != column.end() ; it++){
            for(int i=0 ; i<matrix.size() ; i++){
                matrix[i][it->first] = 0;
            }
        }
    }
};