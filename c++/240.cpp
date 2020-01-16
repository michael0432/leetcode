#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0) return false;
        return search(matrix, target, 0, 0, matrix.size()-1, matrix[0].size()-1);
    }
    bool search(vector<vector<int>>& matrix, int target, int start_i_idx, int start_j_idx, int end_i_idx, int end_j_idx){
        int newstart_iidx, newend_iidx, newstart_jidx, newend_jidx;
        int cnt = 0;
        if(start_i_idx == end_i_idx){
            for(int j=start_j_idx ; j<=end_j_idx ; j++){
                if(matrix[start_i_idx][j] == target) return true;
            }
            return false;
        }
        if(start_j_idx == end_j_idx){
            for(int i=start_i_idx ; i<=end_i_idx ; i++){
                if(matrix[i][start_j_idx] == target) return true;
            }
            return false;
        }
        for(int i=start_i_idx ; i<=end_i_idx ; i++){
            if(target > matrix[i][start_j_idx] && target < matrix[i][end_j_idx]){
                if(cnt == 0) newstart_iidx = i;
                newend_iidx = i;
                cnt += 1;
            }
            if(target == matrix[i][start_j_idx] || target == matrix[i][end_j_idx]) return true;
        }
        if(cnt == 0) return false;
        cnt = 0;
        for(int j=start_j_idx ; j<=end_j_idx ; j++){
            if(target > matrix[start_i_idx][j] && target < matrix[end_i_idx][j]){
                if(cnt == 0) newstart_jidx = j;
                newend_jidx = j;
                cnt += 1;
            }
            if(target == matrix[start_i_idx][j] || target == matrix[end_i_idx][j]) return true;
        }
        if(cnt == 0) return false;
        return search(matrix, target, newstart_iidx, newstart_jidx, newend_iidx, newend_jidx);
    }
};
int main(){
    int target = 24;
    Solution s;
    vector<vector<int>> matrix = {{1,3,5,7,9},{2,4,6,8,10},{11,13,15,17,19},{12,14,16,18,20},{21,22,23,24,25}};
    cout << s.searchMatrix(matrix, target) << endl;
}