class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_set<string> m;
        vector<string> output;
        sort(folder.begin(), folder.end());
        for (int i = 0; i < folder.size(); i++){
            string s = folder[i];
            bool b = false;
            if(m.count(s) != 0)
                b = true;
            while(s.size() != 0 && !b){
                while(s[s.size()-1] != '/'){
                    s.pop_back();
                }
                s.pop_back();
                if(m.count(s) != 0){
                    b = true;
                    break;
                }
            }
            if(b == false){
                output.push_back(folder[i]);
                m.insert(folder[i]);
            }  
        }
        return output;
    }
};