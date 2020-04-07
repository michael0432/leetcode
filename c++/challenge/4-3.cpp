class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        return findMax(nums, 0, nums.size()-1);
    }
    
    int findMax(vector<int>& nums,int sid, int eid){
        if(sid > eid)
            return 0;
        if(sid == eid)
            return nums[sid];
        int mid = (sid + eid) / 2;
        int left = findMax(nums, sid, mid);
        int right = findMax(nums, mid+1, eid);
        int maxi = max(left, right);

        int lm = INT_MIN, sum = 0;
        for (int i = mid; i >= sid; i--){
            sum += nums[i];
            lm = max(lm, sum);
        }

        int rm = INT_MIN;
        sum = 0;
        for (int i = mid+1; i <= eid; i++){
            sum += nums[i];
            rm = max(rm, sum);
        }
        maxi = max(maxi, lm + rm);
        return maxi;
    }
    
};