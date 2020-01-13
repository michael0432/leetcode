#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {

        int c1_max=INT32_MIN, c1_min=INT32_MAX, c2_max=INT32_MIN, c2_min=INT32_MAX, c3_max=INT32_MIN, c3_min=INT32_MAX, c4_max=INT32_MIN, c4_min=INT32_MAX;
        int total_max = 0;
        for(int i=0 ; i<arr1.size() ; i++){
            
            c1_max = max(c1_max,arr1[i]+arr2[i]-i);
            c1_min = min(c1_min,arr1[i]+arr2[i]-i);
            c2_max = max(c2_max,arr2[i]-arr1[i]-i);
            c2_min = min(c2_min,arr2[i]-arr1[i]-i);
            c3_max = max(c3_max,arr1[i]-arr2[i]-i);
            c3_min = min(c3_min,arr1[i]-arr2[i]-i);
            c4_max = max(c4_max,arr2[i]+arr1[i]+i);
            c4_min = min(c4_min,arr2[i]+arr1[i]+i);
        }
        vector<int> tmp = {c1_max-c1_min, c2_max-c2_min, c3_max-c3_min, c4_max-c4_min};
        
        return *max_element(tmp.begin(),tmp.end());
    }
};

int main(){
    Solution s;
    vector<int> arr1 = {1,-2};
    vector<int> arr2 = {8,8};
    cout << s.maxAbsValExpr(arr1,arr2) << endl;
}

