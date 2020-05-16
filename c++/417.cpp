class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<vector<int>> output;
        vector<vector<int>> pacific(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<int>> atlantic(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix.size(); i++){
            int maxi = 0;
            for (int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] >= maxi){
                    maxi = matrix[i][j];
                    pacific[i][j] = 1;
                }
            }
            maxi = 0;
            for (int j = matrix[i].size()-1; j >= 0; j--){
                if(matrix[i][j] >= maxi){
                    maxi = matrix[i][j];
                    atlantic[i][j] = 1;
                }
            }
        }

        for (int j = 0; j < matrix[0].size(); j++){
            int maxi = 0;
            for (int i = 0; i < matrix.size(); i++){
                if(matrix[i][j] >= maxi){
                    maxi = matrix[i][j];
                    pacific[i][j] = 1;
                }
            }
            maxi = 0;
            for (int i = matrix.size()-1; i >= 0; i--){
                if(matrix[i][j] >= maxi){
                    maxi = matrix[i][j];
                    atlantic[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if(pacific[i][j] == 1 && atlantic[i][j] == 1){
                    output.push_back({i, j});
                }
            }
        }
        return output;
    }
};