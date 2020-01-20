#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        return find(nums,1,nums.size());
    }
    int find(vector<int>& nums, int lower_bound, int upper_bound){
        if(lower_bound == upper_bound) return lower_bound;
        int mid = lower_bound + (upper_bound - lower_bound) / 2;
        int smaller = 0, bigger = 0;
        for(int i=0 ; i<nums.size() ; i++){
           if(nums[i] <= mid) smaller += 1;
           else bigger += 1;
        }
        if(smaller <= mid) return find(nums,mid+1,upper_bound);
        else return find(nums,lower_bound,mid);
    }
};

int main(){
    vector<int> nums = {1,3,3,2,4,5};
    Solution s;
    cout << s.findDuplicate(nums) << endl;
}