class Solution {
public:

    unordered_map<int,int> mem;

    int s2mask(string s){
        int mask = 0;
        sort(s.begin(), s.end());
        for(int i=0 ; i<s.size() ; i++){
            if(i != 0 && s[i] == s[i-1]){
                mask = 0;
                break;
            }
            mask = mask | (1<<(s[i] - 'a'));
        }
        return mask;
    }

    int cntmask(int mask){
        int cnt = 0;
        for(int i=0 ; i<26 ; i++){
            if((1<<i) & mask) cnt++;
        }
        return cnt;
    }

    int dfs(vector<string>& arr, int idx, int mask){
        int ans1=0, ans2=0;
        if(idx >= arr.size()){
            return cntmask(mask);
        }
        ans1 = dfs(arr, idx+1, mask); // not put
        if(!(s2mask(arr[idx]) & mask)){
            mask = s2mask(arr[idx]) | mask;
            ans2 = dfs(arr, idx+1, mask); // put
        }
        return max(ans1, ans2);
    }

    int maxLength(vector<string>& arr) {
        return dfs(arr, 0, 0);
    }
};