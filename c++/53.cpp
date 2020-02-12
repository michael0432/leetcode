#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return maxp(nums, 0, nums.size()-1);
    }
    int maxp(vector<int>& nums, int sid, int eid){
        if(sid >= eid) return nums[sid];
        int mid_idx = sid + (eid-sid)/2;
        int left = maxp(nums, sid, mid_idx-1);
        int right = maxp(nums, mid_idx+1, eid);
        int mmax = nums[mid_idx], t = mmax;
        for (int i = mid_idx - 1; i >= sid; --i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        t = mmax;
        for (int i = mid_idx + 1; i <= eid; ++i) {
            t += nums[i];
            mmax = max(mmax, t);
        }
        return max(mmax, max(left, right));
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int maxi = INT_MIN;
        for (int i=0 ; i<nums.size() ; i++){
            int crr = nums[i];
            maxi = max(maxi, crr);
            for(int j=i+1 ; j<nums.size() ; j++){
                crr += nums[j];
                maxi = max(maxi, crr);
            }
        }
        return maxi;
    }
};