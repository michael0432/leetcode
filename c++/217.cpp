#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> m;
        for(int i=0 ; i<nums.size() ; i++){
            if(m.count(nums[i]) != 0){
                return true;
            }
            else{
                m[nums[i]] = true;
            }
        }
        return false;
    }
};