#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        vector<int> v = nums;
        sort(v.begin(), v.end());
        int left_idx = -1, right_idx = -1;
        for(int i=0 ; i<v.size() ; i++){
            if(nums[i] != v[i]){
                left_idx = i;
                break;
            }
        }
        for(int i=v.size()-1 ; i>=0 ; i--){
            if(nums[i] != v[i]){
                right_idx = i;
                break;
            }
        }
        if(left_idx >= right_idx) return 0;
        return right_idx - left_idx+1; 
    }
};