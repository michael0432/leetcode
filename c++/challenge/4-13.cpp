class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int sum = 0, maxlen = 0;
        unordered_map<int, int> m {{0,-1}};
        for (int i = 0; i < nums.size(); i++){
            if(nums[i] == 1)
                sum ++;
            else
                sum --;
            if(m.count(sum) != 0){
                maxlen = max(maxlen, i - m[sum]);
            }
            else{
                m[sum] = i;
            }
        }
        return maxlen;
    }
};