class Solution {
public:

    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), INT_MAX - matrix.size() * matrix[0].size()));

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0)
                    ans[i][j] = 0;
                else{
                    if(i != 0)
                        ans[i][j] = min(ans[i - 1][j] + 1, ans[i][j]);
                    if(j != 0)
                        ans[i][j] = min(ans[i][j - 1] + 1, ans[i][j]);
                }
            }
        }
        for (int i = matrix.size()-1; i >= 0 ; i--){
            for (int j = matrix[i].size()-1; j >= 0; j--){
                if(matrix[i][j] == 0)
                    ans[i][j] = 0;
                else{
                    if(i < matrix.size()-1)
                        ans[i][j] = min(ans[i + 1][j] + 1, ans[i][j]);
                    if(j < matrix[0].size()-1)
                        ans[i][j] = min(ans[i][j + 1] + 1, ans[i][j]);
                }
            }
        }
        return ans;
    }
};