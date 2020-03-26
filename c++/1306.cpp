class Solution {
public:

    bool canReach(vector<int>& arr, int start) {
        unordered_set<int> v;
        return reach(arr, start, v);
    }

    bool reach(vector<int>& arr, int now, unordered_set<int>& v){
        
        if(now < 0 || now > arr.size()-1 || v.count(now)) return false;
        if(arr[now] == 0) return true;
        v.insert(now);
        return reach(arr, now+arr[now], v) || reach(arr, now-arr[now], v);
        
    }
};