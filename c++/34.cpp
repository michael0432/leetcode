#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return search(nums, 0, nums.size()-1, target);
    }
    vector<int> search(vector<int>& nums, int sid, int eid, int target){
        if(sid > eid){
            return {-1,-1};
        }
        else if(sid == eid){
            if(nums[sid] == target){
                return getRange(nums, sid, target);
            }
            else{
                return {-1,-1};
            }
        }
        else{
            if(target > nums[(sid+eid)/2]){
                return search(nums, (sid+eid)/2+1, eid, target);
            }
            else if(target < nums[(sid+eid)/2]){
                return search(nums, sid, (sid+eid)/2-1, target);
            }
            else{
                return getRange(nums, (sid+eid)/2, target);
            }
        }
    }
    vector<int> getRange(vector<int>& nums, int idx, int target){
        int left = idx;
        int right = idx;
        while(left>=0 && nums[left] == target){
            left -= 1;
        }
        while(right<nums.size() && nums[right] == target){
            right += 1;
        }
        return {left+1,right-1};
    }
};