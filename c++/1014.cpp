#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        vector<int> v_i;
        int maxi = INT_MIN, maxj = INT_MIN, maxij = INT_MIN;
        maxj = A[1] - 1;
        maxi = A[0] + 0;
        maxij = maxi + maxj;
        for(int i=2 ; i<A.size() ; i++){
            maxj = max(INT_MIN, A[i] - i);
            maxi = max(maxi, A[i-1] + i-1);
            maxij = max(maxij, maxj+maxi);
        }
        // cout << maxi << " " << maxj << endl;
        return maxij;
    }
};

int main(){
    vector<int> A = {2,2,2};
    Solution s;
    cout << s.maxScoreSightseeingPair(A) << endl;
}