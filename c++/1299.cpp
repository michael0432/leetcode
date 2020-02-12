#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> max_v = arr;
        int maxi = arr[arr.size()-1];
        max_v[arr.size()-1] = -1;
        for(int i=arr.size()-1 ; i>=1 ; i--){
            max_v[i-1] = max(maxi, arr[i]);
            maxi = max_v[i-1];
        }
        return max_v;
    }
};
