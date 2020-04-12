#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> total_set = {};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        subset_recursive(v,nums);
        return total_set;
    }
    void subset_recursive(vector<int> now_v,vector<int> nums){
        if(nums.size() == 0){
            total_set.push_back(now_v);
            return;
        }

        int last_num = nums[nums.size()-1];
        nums.pop_back();
        subset_recursive(now_v,nums);
        now_v.push_back(last_num);
        subset_recursive(now_v,nums);
        
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution s;
    vector<vector<int>> v = s.subsets(nums);
    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[i].size() ; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}


class Solution {
public:
    vector<vector<int>> total_set = {};
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        dfs(nums, v, 0);
        return total_set;
    }
    void dfs(vector<int>& nums, vector<int>& now, int idx){
        if(idx >= nums.size()){
            total_set.push_back(now);
            return;
        }
            
        dfs(nums, now, idx+1);
        now.push_back(nums[idx]);
        dfs(nums, now, idx+1);
        now.pop_back();
    }
};