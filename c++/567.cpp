class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        vector<char> v1(26, 0);
        vector<char> v2(26, 0);
        int l = 0, r = s1.size()-1;
        for (int i = 0; i < s1.size(); i++){
            v1[s1[i] - 'a']++;
        }
        for (int i = l; i <= r; i++){
            v2[s2[i] - 'a']++;
        }
        while(r < s2.size()){
            bool b = true;
            for (int i = 0; i < 26; i++){
                if(v1[i] != v2[i]){
                    b = false;
                    break;
                }
            }
            if(b)
                return b;
            v2[s2[l]-'a']--;
            r++;
            if(r < s2.size())v2[s2[r]-'a']++;
            l++;
        }
        return false;
    }
};