#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < A[i].size()/2; j++){
                swap(A[i][j], A[i][A.size()-1-j]);
            }
        }
        for (int i = 0; i < A.size(); i++){
            for (int j = 0; j < A.size(); j++){
                if(A[i][j] == 1)
                    A[i][j] = 0;
                else
                    A[i][j] = 1;
            }
        }
        return A;
    }
};