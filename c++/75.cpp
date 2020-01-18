#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_idx = 0;
        int two_idx = nums.size()-1;
        for(int i=0 ; i<=two_idx ; i++){
            if(nums[i] == 0){
                swap(nums[zero_idx],nums[i]);
                zero_idx += 1;
            }
            if(nums[i] == 2){
                swap(nums[two_idx],nums[i]);
                two_idx -= 1;
                i--;
            }
        }
    }
};

int main(){
    vector<int> nums {2,0,1};
    Solution s;
    vector<int> n = s.sortColors(nums);
    for(int i=0 ; i<n.size() ; i++){
        cout << n[i] << endl;
    }
}