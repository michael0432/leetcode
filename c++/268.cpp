#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
z
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> v(nums.size()+1,-1);
        for(int i=0 ; i<nums.size() ; i++){
            v[nums[i]] = 1;
        }
        auto it = find(v.begin(),v.end(),-1);
        if(it != v.end()){
            return it-v.begin();
        }
        return -1;
    }
};