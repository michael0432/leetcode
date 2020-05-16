class Solution {
public:
    int minIncrementForUnique(vector<int>& A) {
        if(A.size() == 0) return 0;
        sort(A.begin(), A.end());
        int now_min = A[0], output = 0;
        for (int i = 1; i < A.size(); i++){
            if(A[i] <= now_min){
                now_min += 1;
                output += now_min - A[i];
            }
            else{
                now_min = A[i];
            }
        }
        return output;
    }
};