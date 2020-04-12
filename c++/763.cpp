class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> m;
        vector<int> output;
        for (int i = 0; i < S.size(); i++){
            m[S[i]] = i;
        }
        int start=0, last=0;
        for (int i = 0; i < S.size(); i++){
            last = max(m[S[i]], last);
            if(i == last){
                output.push_back(last - start + 1);
                start = i+1;
            }
        }
        return output;
    }
};