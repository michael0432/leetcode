class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> m;
        int odd_num = 0;
        if(s.size() < k)
            return false;
        for (int i = 0; i < s.size(); i++){
            if(m.count(s[i]))
                m[s[i]]++;
            else
                m[s[i]] = 1;
        }
        for (auto it = m.begin(); it != m.end(); it++){
            if(it->second % 2 == 1)
                odd_num++;
        }
        if(odd_num > k)
            return false;
        else
            return true;
    }
};