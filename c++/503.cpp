class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int> ans(nums.size(), -1);
        for (int x = 0; x <= 1; x++){
            for (int i = 0; i < nums.size(); i++){
                while(!st.empty() && nums[i] > nums[st.top()]){
                    ans[st.top()] = nums[i];
                    st.pop();
                }
                st.push(i);
            }
        }
        return ans;
    }
};