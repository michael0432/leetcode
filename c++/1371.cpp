class Solution {
public:
    int findTheLongestSubstring(string s) {
        int state = 0, maxi = 0;
        unordered_map<int, int> m = {{0,0}};
        for (int i = 0; i < s.size(); i++){
            
            if(s[i] == 'a')
                state = state ^ (1 << 4);
            if(s[i] == 'e')
                state = state ^ (1 << 3);
            if(s[i] == 'i')
                state = state ^ (1 << 2);
            if(s[i] == 'o')
                state = state ^ (1 << 1);
            if(s[i] == 'u')
                state = state ^ (1 << 0);
            if(m.count(state))
                maxi = max(maxi, i + 1 - m[state]);
            else
                m[state] = i+1;
        }
        return maxi;
    }
};