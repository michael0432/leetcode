class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> m;
        int cnt = 0;
        for (int i = 0; i < arr.size(); i++){
            m.insert(arr[i]);
        }
        for (int i = 0; i < arr.size(); i++){
            if(m.count(arr[i]+1) != 0)
                cnt++;
        }
        return cnt;
    }
};