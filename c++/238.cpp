#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> front;
        vector<int> back;
        vector<int> out;
        int cnt1 = 1;
        int cnt2 = 1;
        for(int i=0 ; i<nums.size() ; i++){
            cnt1 *= nums[i];
            cnt2 *= nums[nums.size()-i-1];
            front.push_back(cnt1);
            back.push_back(cnt2);
            cout << cnt1 << " " << cnt2 << endl;
        }
        
        for(int i=0 ; i<nums.size() ; i++){
            if(i == 0)
                out.push_back(back[nums.size()-2]);
            else if(i == nums.size()-1)
                out.push_back(front[nums.size()-2]);
            else
                out.push_back(front[i-1]*back[nums.size()-i-2]);
        }
        return out;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution s;
    vector<int> out;
    out = s.productExceptSelf(nums);
    for(int i=0 ; i<out.size() ; i++){
        cout << out[i] << " ";
    }

}