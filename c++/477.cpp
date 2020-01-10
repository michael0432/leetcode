#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int total_dis = 0;
        
        for(int i=0 ; i<32 ; i++){
            int zero_count = 0;
            int one_count = 0;
            for(int j=0 ; j<nums.size() ; j++){
                if((nums[j] & (1 << i)) == 0){
                    zero_count += 1;
                }
                else{
                    one_count += 1;
                }
            }
            one_count = nums.size() - zero_count;
            
            total_dis += zero_count * one_count;
            
        }
        return total_dis;
    }
};

int main(){
    Solution s;
    vector<int> nums = {4,14,2};
    s.totalHammingDistance(nums);
    // cout << s.totalHammingDistance(nums) << endl;
} 