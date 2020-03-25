class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        dfs(characters, "", combinationLength, 0);
        now_idx = 0;
    }
    
    string next() {
        now_idx += 1;
        return all_com[now_idx-1];
    }
    
    bool hasNext() {
        if(now_idx <= all_com.size()-1) return true;
        return false;
    }
private:
    vector<string> all_com;
    int now_idx;
    void dfs(string characters, string now_s, int combinationLength, int idx){
        if(now_s.size() == combinationLength){
            all_com.push_back(now_s);
            return;
        }
        if(idx >= characters.size()) return;
        // choose
        dfs(characters, now_s+characters[idx], combinationLength, idx+1);
        // not choose
        dfs(characters, now_s, combinationLength, idx+1);
    }
};