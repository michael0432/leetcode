#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size() == 0) return 0;
        heights.push_back(0);
        int max_area = 0;
        stack<int> st;
        for(int i=0 ; i<heights.size() ; i++){
            while(!st.empty() && heights[i] < heights[st.top()]){
                int val = st.top();
                st.pop();
                int left;
                if(st.empty()) left = i;
                else left = i - st.top() - 1;
                max_area = max(max_area, heights[val] * left);
            }
            st.push(i);
        }
        return max_area;
    }
};

int main(){
    vector<int> heights = {2,1,5,6,2,3};
    Solution s;
    cout << s.largestRectangleArea(heights) << endl;
}