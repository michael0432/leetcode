#include <string>
#include <iostream>
#include <vector>
#include <tuple>
#include <unordered_map>

using namespace std;


class Solution {
public:

    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> mapMax;
        int sum = 0;
        int max = 0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == 1){
                sum += 1;
            }
            else{
                sum -= 1;
            }
            if(mapMax.count(sum) == 0){
                mapMax.insert({sum,i});
            }
            else{
                int len = i - mapMax[sum];
                if(len > max){
                    max = len;
                }
            }
        }
        return max;
    }
    
};

int main(){
    Solution s;
    vector<int> n = {1,0,0,1};
    cout << s.findMaxLength(n) << endl;
}