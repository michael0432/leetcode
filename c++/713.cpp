#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int cross_sum = 1;
        int cnt = 0;
        while(right < nums.size()){
            cross_sum *= nums[right];
            while(cross_sum >= k){
                cross_sum /= nums[left];
                left += 1;
                if(left > right) break;
            }
            cnt += right - left + 1;
            right += 1;
        }
        return cnt;
    }
};

int main(){
    vector<int> nums = {10,5,2,6};
    int k = 100;
    Solution s;
    cout << s.numSubarrayProductLessThanK(nums,k) << endl;
}