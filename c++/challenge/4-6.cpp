class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> m;
        vector<string> tmp = strs;
        vector<vector<string>> output;
        for (int i = 0; i < tmp.size(); i++){
            sort(tmp[i].begin(), tmp[i].end());
            if(m.count(tmp[i]))
                m[tmp[i]].push_back(i);
            else
                m[tmp[i]] = {i};
        }
        for (auto it = m.begin(); it != m.end() ; it++){
            output.push_back({});
            for (int i = 0; i < it->second.size(); i++){
                output[output.size() - 1].push_back(strs[it->second[i]]);
            }
        }
        return output;
    }
};