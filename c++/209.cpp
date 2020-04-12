class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int l = 0, r = 0, sum = 0, minlen = INT_MAX;
        while(r < nums.size()){
            sum += nums[r];
            while(sum >= s){
                minlen = min(minlen, r - l+1);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        if(minlen == INT_MAX )
            return 0;
        return minlen;
    }
};