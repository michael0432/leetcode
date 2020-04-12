class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(s.size() < p.size())
            return {};
        vector<int> vs(26, 0);
        vector<int> vp(26, 0);
        vector<int> output;
        int l = 0, r = p.size() - 1;
        for (int i = 0; i < p.size(); i++){
            vp[p[i] - 'a']++;
            vs[s[i] - 'a']++;
        }
        while(r < s.size()){
            bool b = true;
            for (int i = 0; i < 26; i++){
                if(vs[i] != vp[i]){
                    b = false;
                    break;
                }
            }
            if(b)
                output.push_back(l);

            vs[s[l] - 'a']--;
            l++;
            r++;
            if(r < s.size()) vs[s[r] - 'a']++;
        }
        return output;
    }
};