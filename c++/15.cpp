#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> out = {};
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out = {};
        int n = nums.size();
        if(n < 3) return out;
        sort(nums.begin(),nums.end());       
        for(int i=0 ; i<nums.size()-2 ; i++){
            if(nums[i] > 0) break;
            if(i != 0 && nums[i] == nums[i-1]) continue;
            int left = i+1, right = nums.size()-1, target = -nums[i];
            while(left < right){
                if(nums[left] + nums[right] > target){
                    right -= 1;
                }
                else if(nums[left] + nums[right] < target){
                    left += 1;
                }
                else{
                    out.push_back({nums[i],nums[left],nums[right]});
                    while(left < right && nums[right] == nums[right-1]) right -= 1;
                    while(left < right && nums[left] == nums[left+1]) left += 1;
                    left += 1;
                    right -= 1;
                }
                
            }
        }
        return out;
    }
};

int main(){
    vector<int> nums = {0,0,0};
    Solution s;
    vector<vector<int>> v = s.threeSum(nums);

    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[i].size() ; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}