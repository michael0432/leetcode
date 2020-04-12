class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> m;
        int l = 0, r = 0, maxl = 0;
        while(r < s.size()){
            if(m.count(s[r]) == 0 || m[s[r]] == 0){
                m[s[r]] = 1;
                r++;
            }
            else{
                m[s[l]]--;
                l++;
            }
            maxl = max(maxl, r - l);
        }
        return maxl;
    }
};