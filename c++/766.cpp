#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++){
            int start_num = matrix[i][0];
            int r = i+1, c = 1;
            while(r < matrix.size() && c < matrix[0].size()){
                if(matrix[r][c] != start_num)
                    return false;
                r += 1;
                c += 1;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++){
            int start_num = matrix[0][i];
            int r = 1, c = i+1;
            while(r < matrix.size() && c < matrix[0].size()){
                if(matrix[r][c] != start_num)
                    return false;
                r += 1;
                c += 1;
            }
        }
        return true;
    }
};