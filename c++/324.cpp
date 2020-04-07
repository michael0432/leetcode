class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> output = nums;
        int idx1 = (nums.size() - 1) / 2;
        int idx2 = nums.size() - 1;
        for (int i = 0; i < nums.size(); i++){
            if(i % 2 == 0){
                output[i] = nums[idx1];
                idx1--;
            }
            else{
                output[i] = nums[idx2];
                idx2--;
            }
                
        }
        nums = output;
    }
};