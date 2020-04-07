class Solution {
public:
    int maximumSum(vector<int>& arr) {
        vector<int> dpfront(arr.size());
        vector<int> dpend(arr.size());
        dpfront[0] = arr[0];
        dpend[arr.size() - 1] = arr[arr.size() - 1];
        int ans = INT_MIN;
        for (int i = 1; i < arr.size(); i++){
            dpfront[i] = arr[i] + max(dpfront[i - 1], 0);
        }
        for (int i = arr.size() - 2; i >= 0; i--){
            dpend[i] = arr[i] + max(dpend[i + 1], 0);
        }
        for (int i = 1; i < arr.size()-1; i++){
            ans = max(ans, dpfront[i - 1] + dpend[i + 1]);
        }
        return ans;
    }
};