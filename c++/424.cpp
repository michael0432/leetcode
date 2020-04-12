class Solution {
public:

    int mF(unordered_map<char, int> m){
        int cnt = 0;
        for (auto it = m.begin(); it != m.end(); it++){
            //cout << "mf: " << it->first << " " << it->second << endl;
            cnt = max(it->second, cnt);
        }
        return cnt;
    }

    int characterReplacement(string s, int k) {
        unordered_map<char, int> m = {{s[0],1}};
        int l = 0, r = 0, maxlen = 0;
        while(r < s.size()){
            //cout << l << " " << r << endl;
            int slen = r - l + 1;
            int mostFreq = mF(m);
            
            if(slen - mostFreq > k){
                m[s[l]]--; 
                l++;
            }
            else{
                r++;
                if(r < s.size()) m[s[r]]++;
            }
            
            maxlen = max(maxlen, r - l);
        }
        return maxlen;
    }
};