#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> out;
        for(int i=0 ; i<nums.size() ; i++){
            while(!q.empty() && q.front() < i-k+1) q.pop_front();
            while(!q.empty() && nums[q.back()] < nums[i]) q.pop_back();
            q.push_back(i);
            if(k-i <= 1) out.push_back(nums[q.front()]);
            // for(int i=0 ; i<q.size() ; i++){
            //     cout << q[i] << " " << nums[q[i]] << ",";
            // }
            // cout << endl;
        }
        return out;
    }
};

int main(){
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    Solution s;
    vector<int> v = s.maxSlidingWindow(nums, k);
    for(int i=0 ; i<v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}