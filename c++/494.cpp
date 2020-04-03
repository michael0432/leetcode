#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    int findTargetSumWays(vector<int>& nums, int S) {
        return recursive(nums,S,0);
    }
    int recursive(vector<int>& nums, int S, int idx){
        if(idx >= nums.size()){
            if(S == 0) 
                return 1;
            else
                return 0;
        }
        if(S > 0 && nums[idx] > 0 && S > INT32_MAX - nums[idx]){
            return recursive(nums,S-nums[idx],idx+1);
        }
        if(S < 0 && nums[idx] < 0 && S < INT32_MIN - nums[idx]){
            return recursive(nums,S+nums[idx],idx+1);
        }
        
        return recursive(nums,S+nums[idx],idx+1)+recursive(nums,S-nums[idx],idx+1); 
    }
};

class Solution {
public:
    long long int total = 0;
    int findTargetSumWays(vector<int>& nums, int S) {
        recursive(nums,(long long)S,0);
        return (int)total;
    }
    void recursive(vector<int>& nums, long long S, int idx){
        if(idx >= nums.size()){
            if(S == 0)
                total++;
            return;
        }
        recursive(nums, S - nums[idx], idx + 1);
        recursive(nums, S + nums[idx], idx + 1);
        return;
    }
};


int main(){
    vector<int> nums = {0,0,0,0,0,0,0,0,1};
    int target = 1;
    Solution s;
    cout << s.findTargetSumWays(nums, target) << endl;
}