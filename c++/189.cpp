#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> mem = nums;
        for(int i=0 ; i<nums.size() ; i++){
            nums[(i+k) % nums.size()] = mem[i];
        }
    }
};