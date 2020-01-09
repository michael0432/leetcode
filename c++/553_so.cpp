#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        if(nums.size() == 0){
            return "";
        }
        string s = to_string(nums[0]);
        if(nums.size() == 1){
            return s;
        }
        else if(nums.size() == 2){
            return s + "/" + to_string(nums[1]);
        }
        else{
            s += "/(";
            s += to_string(nums[1]);
            for(int i=2 ; i<nums.size() ; i++){
                s += "/" + to_string(nums[i]);
            }
            s += ")";
            return s;
        }
    }

    
};
int main(){
        vector<int> nums = {300,1000,100,10,2};
        
        Solution s;
        s.optimalDivision(nums);
        // cout << s.magicalString(20) << endl;
    }