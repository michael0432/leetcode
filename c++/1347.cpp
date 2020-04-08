class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        int dif = 0;
        for (int i = 0; i < s.size(); i++){
            if(m1.count(s[i]) == 0)
                m1[s[i]] = 1;
            else
                m1[s[i]]++;
        }
        for (int j = 0; j < t.size(); j++){
            if(m2.count(t[j]) == 0)
                m2[t[j]] = 1;
            else
                m2[t[j]]++;
        }
        for (auto it = m2.begin(); it != m2.end(); it++){
            if(m1.count(it->first) == 0){
                dif += it->second;
            }
            else if(m1[it->first] < it->second)
                dif += it->second - m1[it->first];
        }
        return dif;
    }
};