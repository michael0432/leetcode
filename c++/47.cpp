#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int,bool> map;
        vector<vector<int>> output;
        if(nums.size() == 1){
            vector<int> c = {nums[0]};
            output.push_back(c);
            return output;
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(map.count(nums[i]) != 0) continue;
            else map[nums[i]] = true;
            vector<int> n = nums;
            n.erase(n.begin()+i);
            vector<vector<int>> tmp = permuteUnique(n);
            
            for(int j=0 ; j<tmp.size() ; j++){
                
                tmp[j].insert(tmp[j].begin(),nums[i]);
                output.push_back(tmp[j]);
                  
            }
        }
        return output;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2};
    Solution s;
    vector<vector<int>> v = s.permuteUnique(nums);
    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[i].size() ; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}

