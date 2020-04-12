class Solution {
public:

    bool isSub(string a, string b){
        auto position = b.find(a);
        if(position != b.npos)
            return true;
        else
            return false;
    }

    vector<string> stringMatching(vector<string>& words) {
        vector<string> output;
        sort(words.begin(), words.end(), [](const string &a, const string &b) {
            return a.size() > b.size();
        });
        for (int i = 0; i < words.size(); i++){
            for (int j = i - 1; j >= 0;j--){
                if(isSub(words[i], words[j])){
                    output.push_back(words[i]);
                    break;
                }
            }
        }
        return output;
    }
};