#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> two_d = {1};
    int findMaximumXOR(vector<int>& nums) {
        int max_digit = INT_MIN;
        int min_digit = INT_MAX;
        vector<int> dig_v;
        vector<int> max_v;
        vector<int> min_v;
        int max_out = INT_MIN;
        for(int i=1 ; i<=31 ; i++){
            two_d.push_back(two_d[i-1]*2);
        }
        for(int i=0 ; i<nums.size() ; i++){
            int dig = getDigit(nums[i]);
            max_digit = max(max_digit, dig);
            min_digit = min(min_digit, dig);
            dig_v.push_back(dig);
        }
        for(int i=0 ; i<nums.size() ; i++){
            if(dig_v[i] == max_digit) max_v.push_back(nums[i]);
            else if(dig_v[i] == min_digit) min_v.push_back(nums[i]);
        }
        for(int i=0 ; i<max_v.size() ; i++){
            for(int j=0 ; j<min_v.size() ; j++){
                max_out = max(max_out, max_v[i] ^ min_v[j]);
            }
        }
        return max_out;
    }
    int getDigit(int n){
        for(int i=0 ; i<two_d.size() ; i++){
            if(n < two_d[i]) return i;
        }
        return 31;
    }
};

int main(){
    
    int x = 7;
    Solution s;
    vector<int> v = {1,2,3};
    s.findMaximumXOR(v);
    cout << s.getDigit(x) << endl;
}