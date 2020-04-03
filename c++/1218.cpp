class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> map;
        vector<int> dp(arr.size(),1);
        int max_len = 1;
        for (int i = 0; i < arr.size(); i++){
            if(map.count(arr[i] - difference)){
                map[arr[i]] = map[arr[i] - difference] + 1;
                max_len = max(max_len, map[arr[i]]);
            }
            else
                map[arr[i]] = 1;
        }
        return max_len;
    }
};