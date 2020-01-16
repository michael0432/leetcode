#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        dp.resize(nums.size(),0);
        return jump(nums,0);
    }
    bool jump(vector<int>& nums,int idx){
        
        if(idx > nums.size()-1){
            dp[idx] = -1;
            return false;
        } 
        if(idx == nums.size()-1){
            dp[idx] = 1;
            return true;
        } 
        for(int i=1 ; i<=nums[idx] ; i++){
            if(idx+i >= nums.size()) break;
            if(dp[idx+i] == 1) return true;
            if(dp[idx+i] == -1) continue;
            if(jump(nums,idx+i)){
                dp[idx+i] = 1;
                return true;
            } 
            else{
                dp[idx+i] = -1;
            }
        }
        dp[idx] = -1;
        return false;
    }
};

int main(){
    vector<int> nums = {3,0,8,2,0,0,1};
    Solution s;
    cout << s.canJump(nums) << endl;
}
