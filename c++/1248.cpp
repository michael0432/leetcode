class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> m = {{0,1}};
        int sum = 0, cnt = 0;
        for(int i=0 ; i<nums.size() ; i++){
            nums[i] = nums[i] % 2;
            sum += nums[i];
            cnt += m[sum - k];
            m[sum]++;
        }
        return cnt;
    }
};