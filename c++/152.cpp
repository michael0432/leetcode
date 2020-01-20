#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> max_v = {nums[0]};
        vector<int> min_v = {nums[0]};
        int max_value = nums[0];
        for(int i=1 ; i<nums.size() ; i++){
            int nowmax = max(max_v[i-1] * nums[i] , nums[i]);
            nowmax = max(nowmax , min_v[i-1] * nums[i]);
            if(nowmax > max_value) max_value = nowmax;
            int nowmin = min(max_v[i-1] * nums[i] , nums[i]);
            nowmin = min(nowmin , min_v[i-1] * nums[i]);
            max_v.push_back(nowmax);
            min_v.push_back(nowmin);
        }
        return max_value;
    }
};

int main(){
    vector<int> nums = {2,-1,1,1};
    Solution s;
    cout << s.maxProduct(nums) << endl;
}