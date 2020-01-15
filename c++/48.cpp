#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    
    vector<vector<int>> rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
        for(int j=0 ; j<n/2 ; j++){
            for(int i=0 ; i<n ; i++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[i][n-j-1];
                matrix[i][n-j-1] = tmp;
            }
        }
        return matrix;
    }
    
};

int main(){
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    Solution s;
    matrix = s.rotate(matrix);
    int n = matrix.size();
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<n ; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}