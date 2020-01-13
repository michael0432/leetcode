#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int sum = 0;
        unordered_map<int,int> map{{0,1}};
        for(int i=0 ; i<nums.size() ; i++){
            sum += nums[i];
            cnt += map[sum-k];
            map[sum] += 1;
        }
        return cnt;
    }
};

int main(){
    vector<int> v = {1};
    int k = 1;
    Solution s;
    cout << s.subarraySum(v,k) << endl;
}