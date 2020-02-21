#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = INT_MIN;
        int idx_left = 0, idx_right = height.size()-1;
        while(idx_left < idx_right){
            maxi = max(maxi, min(height[idx_left],height[idx_right]) * (idx_right-idx_left));
            if(height[idx_left] < height[idx_right]) idx_left++;
            else idx_right--;
        }
        return maxi;
    }
};