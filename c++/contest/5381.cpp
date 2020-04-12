class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        unordered_map<int, int> map;
        vector<int> output;
        for (int i = 1; i <= m; i++){
            map[i] = i-1;
        }
        for (int i = 0; i < queries.size(); i++){
            int pos = map[queries[i]];
            output.push_back(pos);
            for (auto it = map.begin(); it != map.end(); it++){
                if(it->second < pos){
                    it->second++;
                }
            }
            map[queries[i]] = 0;
        }
        return output;
    }
};