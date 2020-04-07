class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int x = 0, y = 0;
        while(y < nums.size() && x < nums.size()){
            if(nums[y] == 0)
                y++;
            else{
                if(nums[x] == 0) swap(nums[x], nums[y]);
                x++;
                y++;
            }
        }
    }
};