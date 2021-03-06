#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for(int i=0 ; i<nums.size() ; i++){
            if(m.count(nums[i])) m[nums[i]] += 1;
            else m[nums[i]] = 1;
        }
        for(auto it = m.begin() ; it != m.end() ; it++){
            if (it->second == 1) return it->first;
        }
        return -1;
    }
};