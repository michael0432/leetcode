#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> output = {};
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        vector<int> v = {};
        for(int i=1 ; i<=n ; i++){
            nums.push_back(i);
        }
        
        recursive(nums, v, k);
        return output;
    }
    void recursive(vector<int>& nums, vector<int>& now_nums, int k){
        
        if(now_nums.size() == k){
            output.push_back(now_nums);
            return;
        }  
        if(nums.size() <= 0){
            return;
        }
        if(now_nums.size() > k){
            return;
        }
        else{
            int tmp = nums[0];
            nums.erase(nums.begin());
            recursive(nums,now_nums,k);
            now_nums.push_back(tmp);
            recursive(nums,now_nums,k);
            now_nums.pop_back();
            nums.insert(nums.begin(),tmp);
        }
        return;
    }
};

int main(){
    int n = 5;
    int k = 2;
    Solution s;
    vector<vector<int>> v = s.combine(n,k);
    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[i].size() ; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}