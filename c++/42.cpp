#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 0) return 0;
        vector<int> left_v;
        vector<int> right_v;
        int max_l = INT_MIN, max_r = INT_MIN;
        int cnt = 0;
        for(int i=0 ; i<height.size() ; i++){
            max_l = max(max_l, height[i]);
            left_v.push_back(max_l);
        }
        for(int i=height.size()-1 ; i>=0 ; i--){
            max_r = max(max_r, height[i]);
            right_v.push_back(max_r);
        }
        for(int i=1 ; i<height.size()-1 ; i++){
            if(height[i] < left_v[i-1] && height[i] < right_v[height.size()-2-i]){
                cnt += min(left_v[i-1], right_v[height.size()-2-i]) - height[i];
            }
        }
        return cnt;
    }
};

int main(){
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    Solution s;
    cout << s.trap(height) << endl;
}