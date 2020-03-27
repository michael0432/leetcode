class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> mod31;
        vector<int> mod32;
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] % 3 == 1){
                mod31.push_back(nums[i]);
            }
            else if(nums[i] % 3 == 2){
                mod32.push_back(nums[i]);
            }
            sum += nums[i];
        }
        sort(mod31.begin(), mod31.end());
        sort(mod32.begin(), mod32.end());

        if(sum % 3 == 0) return sum;
        else if(sum % 3 == 1){
            int sum31, sum32;
            if(mod31.size() == 0)
                sum31 = sum;
            else sum31 = mod31[0];
            if(mod32.size() <= 1)
                sum32 = sum;
            else sum32 = mod32[0] + mod32[1];
            return max(sum-sum31, sum-sum32);
        }
        else{
            int sum31, sum32;
            if(mod32.size() == 0) sum32 = sum;
            else sum32 = mod32[0];
            if(mod31.size() <= 1) sum31 = sum;
            else sum31 = mod31[0] + mod31[1];
    
            return max(sum-sum31, sum-sum32);
        }
    }
};