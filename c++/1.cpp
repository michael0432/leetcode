#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0 ; i<nums.size() ; i++){
            if(map.count(nums[i]) == 0){
                map[target-nums[i]] = i;
            }
            else{
                return {map[nums[i]],i};
            }
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9;
    Solution s;
    vector<int> v = s.twoSum(nums, target);
    for(int i=0 ; i<v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}