class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        vector<int> left_max(A.size());
        vector<int> right_min(A.size());
        left_max[0] = A[0];
        right_min[A.size()-1] = A[A.size()-1];
        for (int i = 1; i < A.size(); i++){
            left_max[i] = max(left_max[i - 1], A[i]);
        }
        for (int i = A.size()-2; i >= 0; i--){
            right_min[i] = min(right_min[i + 1], A[i]);
        }
        for (int i = 0; i < A.size()-1; i++){
            if(left_max[i] <= right_min[i+1])
                return i + 1;
        }
        return -1;
    }
};