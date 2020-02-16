#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> m;
        vector<vector<string>> out_v;
        for (int i = 0; i < strs.size(); i++){
            string news = strs[i];
            sort(news.begin(), news.end());
            if(m.count(news) == 0){
                m[news] = {strs[i]};
            }
            else{
                m[news].push_back(strs[i]);
            }
        }
        for (auto it = m.begin(); it != m.end(); it++){
            out_v.push_back(it->second);
        }
        return out_v;
    }
};