#include <iostream>
#include <vector>

using namespace std;

int main(){
    
    long long n;
    while(cin >> n){
        vector<long long> nums = {n};
        while(cin >> n && n != -999999){
            nums.push_back(n);
        }
        vector<long long> maxv(nums.size());
        vector<long long> minv(nums.size());
        maxv[0] = nums[0];
        minv[0] = nums[0];
        long long res = maxv[0];
        for (int i = 1; i < nums.size(); i++){
            maxv[i] = nums[i];
            minv[i] = nums[i];
            maxv[i] = max(max(nums[i],nums[i] * maxv[i - 1]), nums[i] * minv[i - 1]);
            minv[i] = min(min(nums[i],nums[i] * maxv[i - 1]), nums[i] * minv[i - 1]);
            res = max(maxv[i], res);
        }
        cout << res << endl;
    }
}