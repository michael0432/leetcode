#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int s_ptr = 0;
        int e_ptr = A.size()-1;
        vector<int> out_vec = A;
        int out_ptr = A.size()-1;
        while(out_ptr >= 0){
            if(A[s_ptr] * A[s_ptr] >= A[e_ptr] * A[e_ptr]){
                out_vec[out_ptr] = A[s_ptr] * A[s_ptr];
                s_ptr += 1;
            }
            else{
                out_vec[out_ptr] = A[e_ptr] * A[e_ptr];
                e_ptr -= 1;
            }
            out_ptr -= 1;
        }
        return out_vec;
    }
};