class Solution {
public:
    int balancedString(string s) {
        int l = 0, r = 0, output = INT_MAX;
        int limit = s.size() / 4;
        vector<int> v(s.size()+1,0);
        vector<int> word = {'Q', 'W', 'E', 'R'};
        unordered_map<char, vector<int>> m = {{'W', v}, {'Q', v}, {'E', v}, {'R', v}};
        for (int i = 0; i < s.size(); i++){
            for (auto it = m.begin(); it != m.end(); it++){
                if(it->first == s[i]){
                    cout << "here" << endl;
                    m[s[i]][i+1] = m[s[i]][i] + 1;
                }
                    
                else
                    m[s[i]][i+1] = m[s[i]][i];
            }
        }
        
        while(r <= s.size() && l <= r){
            bool flag = false;
            for(int w: word){
                if(m[w][s.size()] - m[w][r] + m[w][l] > limit){
                    r++;
                    flag = true;
                    break;
                }
            }
            if(flag)
                continue;
            output = min(output, r - l);
            l++;
        }
        return output;
    }
};