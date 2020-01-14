#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> output = {};
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        recursive({},candidates,target,0);
        return output;
    }
    void recursive(vector<int> now, vector<int>& candidates, int target, int start){
        if(target < 0) return;
        if(target == 0){
            output.push_back(now);
            return;
        }
        for(int i=start ; i<candidates.size() ; i++){
            vector<int> n = now;
            n.push_back(candidates[i]);
            recursive(n,candidates,target-candidates[i],i);
        }
    }
};

int main(){
    vector<int> nums {2,3,5};
    int target = 8;
    Solution s;
    
    vector<vector<int>> v = s.combinationSum(nums,target);
    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[i].size() ; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
