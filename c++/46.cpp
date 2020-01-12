#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> output;
        if(nums.size() == 1){
            vector<int> c = {nums[0]};
            output.push_back(c);
            return output;
        }
        for(int i=0 ; i<nums.size() ; i++){
            vector<int> n = nums;
            n.erase(n.begin()+i);
            
            vector<vector<int>> tmp = permute(n);
            for(int j=0 ; j<tmp.size() ; j++){
                tmp[j].insert(tmp[j].begin(),nums[i]);
                output.push_back(tmp[j]);
            }
        }
        return output;
    }
};
int main(){
    vector<int> nums = {1,2,3,4,5,6};
    
    Solution s;
    vector<vector<int>> tmp = s.permute(nums);
    for(int i=0 ; i<tmp.size() ; i++){
       for(int j=0 ; j<tmp[i].size() ; j++){
           cout << tmp[i][j];
        } 
        cout << endl;
    }
}