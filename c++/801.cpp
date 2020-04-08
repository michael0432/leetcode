class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<int> swap(A.size(),INT_MAX);
        vector<int> keep(A.size(),INT_MAX);
        swap[0] = 1;
        keep[0] = 0;
        for (int i = 1; i < keep.size(); i++){
            if(A[i] > A[i-1] && B[i] > B[i-1]){
                swap[i] = swap[i - 1] + 1;
                keep[i] = keep[i-1];
            }
            if(A[i] > B[i-1] && B[i] > A[i-1]){
                swap[i] = min(keep[i - 1] + 1, swap[i]);
                keep[i] = min(keep[i], swap[i - 1]);
            }
        }
        return min(keep[A.size()-1],swap[A.size()-1]);
    }
};