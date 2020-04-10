class Solution {
public:

    string solve(string s){
        string st;
        for (int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(st.size() != 0) st.pop_back();
            }
            else{
                st.push_back(s[i]);
            }
        }
        return st;
    }

    bool backspaceCompare(string S, string T) {
        cout << solve(S) << " " << solve(T) << endl;
        return solve(S) == solve(T);
    }
};