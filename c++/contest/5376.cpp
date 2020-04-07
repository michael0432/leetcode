class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        vector<int> output;
        int sum = 0, half = 0;
        for (int i = 0; i < nums.size(); i++){
            sum += nums[i];
        }
        
        for (int i = 0; i < nums.size(); i++){
            half += nums[i];
            output.push_back(nums[i]);
            if(half > (double)sum / 2){
                break;
                
            }
        }
        return output;
    }
};