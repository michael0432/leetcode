#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int p1 = 0;
        int move_zero_nums = 0;
        while(p1 < nums.size() - move_zero_nums){
            if(nums[p1] == 0){
                for(int p2 = p1+1; p2 < nums.size() ; p2++){
                    swap(nums[p2-1],nums[p2]);
                }
                move_zero_nums += 1;
            }
            if(nums[p1] != 0) p1+=1;
        }
    }
};

int main(){
    Solution s;
    vector<int> nums = {};
    s.moveZeroes(nums);
}