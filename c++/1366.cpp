class Solution {
public:
    string rankTeams(vector<string>& votes) {
        vector<vector<int>> vec(votes[0].size(), vector<int>(26, 0));
        for(auto v: votes){
            for(int i=0 ; i<votes[0].size() ; i++){
                vec[i][v[i] - 'A']++;
            }
        }
        string ans = votes[0];
        sort(ans.begin(), ans.end(),[&](char a, char b){
            for(int i=0 ; i<votes[0].size() ; i++){
                if(vec[i][a-'A'] == vec[i][b-'A']){
                    continue;
                }
                else{
                    return vec[i][a-'A'] > vec[i][b-'A'];
                }
            }
            return a < b;
        });
        return ans;
    }
};