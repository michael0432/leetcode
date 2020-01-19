#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return binary_search(nums, target, 0, nums.size()-1);
    }
    int binary_search(vector<int>& nums, int target, int s_i, int e_i){
        // cout << s_i << " " << e_i << endl;
        if(s_i > e_i) return -1;
        if(s_i == e_i){
            if(nums[s_i] == target) return s_i;
            else return -1;
        }
        if(nums[s_i + (e_i-s_i)/2] == target) return s_i + (e_i-s_i)/2;
        if(nums[s_i] == target) return s_i;
        if(nums[e_i] == target) return e_i;
        if(nums[s_i + (e_i-s_i)/2] < nums[e_i]){
            if(nums[s_i + (e_i-s_i)/2] < target && nums[e_i] >= target) return binary_search(nums, target, s_i + (e_i-s_i)/2 + 1, e_i);
            else return binary_search(nums, target, s_i, s_i + (e_i-s_i)/2 - 1);
        }
        else{
            // cout << "test: " << nums[s_i + (e_i-s_i)/2] << " " << nums[s_i] << " " << target;
            if(nums[s_i + (e_i-s_i)/2] > target && nums[s_i] <= target) return binary_search(nums, target, s_i, s_i + (e_i-s_i)/2 - 1);
            else return binary_search(nums, target, s_i + (e_i-s_i)/2 + 1, e_i);
        }
        return -1;
    }
};

int main(){
    int target = 6;
    vector<int> nums = {8,1,2,3,4,5,6,7};
    Solution s;
    cout << s.search(nums, target) << endl;
}