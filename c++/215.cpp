#include <vector>
#include <iostream>
#include <random>
using namespace std;

class Solution {
public:
    int ans;
    int findKthLargest(vector<int>& nums, int k) {
        quickSort(nums, k);
        return ans;
    }

    void quickSort(vector<int> nums, int k){
        vector<int> left;
        vector<int> right;
        if(nums.size() == 0){
            return;
        }
        
        for(int i=1 ; i<nums.size() ; i++){
            
            if(nums[i] < nums[0]){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);
            }
        }
        
        if(right.size() > k-1){
            quickSort(right,k);
        }
        else if(right.size() < k-1){
            quickSort(left,k-right.size()-1);
        }
        else{
            ans = nums[0];
            return;
        }
        return;
        
    }
};

int main(){
    vector<int> nums = {2,1};
    int k = 2;
    Solution s;
    cout << s.findKthLargest(nums,k) << endl;
}