class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int i=0 ; i<mat.size() ; i++){
            int x = i, y = 0;
            vector<int> v;
            while(x < mat.size() && y < mat[0].size()){
                v.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(v.begin(), v.end());
            x = i;
            y = 0;
            while(x < mat.size() && y < mat[0].size()){
                mat[x][y] = v[y];
                x++;
                y++;
            }
        }
        for(int i=0 ; i<mat[0].size() ; i++){
            int x = 0, y = i;
            vector<int> v;
            while(x < mat.size() && y < mat[0].size()){
                v.push_back(mat[x][y]);
                x++;
                y++;
            }
            sort(v.begin(), v.end());
            x = 0;
            y = i;
            while(x < mat.size() && y < mat[0].size()){
                mat[x][y] = v[x];
                x++;
                y++;
            }
        }
        return mat;
    }
};