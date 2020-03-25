class Solution {
public:

    vector<int> set;

    int find(int x){
        return x == set[x] ? x : set[x] = find(set[x]);
    }
    bool equal(int x, int y){
        return find(x) == find(y);
    }
    void unions(int x, int y){
        set[find(x)] = find(y);
        return;
    }

    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        set.resize(s.size(),-1);
        unordered_map<int, vector<int>> m;
        
        string output = s;
        for(int i=0 ; i<s.size() ; i++){
            set[i] = i;
        }
        for(int i=0 ; i<pairs.size() ; i++){
            if(!equal(pairs[i][0],pairs[i][1])){
                unions(pairs[i][0],pairs[i][1]);
            }
        }
        vector<string> all_s(s.size());
        vector<vector<int>> sorted_set(s.size());
        for(int i=0 ; i<s.size() ; i++){
            int id = find(i);
            sorted_set[id].push_back(i);
            all_s[id].push_back(s[i]);
        }
        for(int i=0 ; i<s.size() ; i++){
            sort(all_s[i].begin(), all_s[i].end());
            for(int k=0 ; k<sorted_set[i].size() ; k++){
                s[sorted_set[i][k]] = all_s[i][k];
            }
        }
        
        return s;
    }
};