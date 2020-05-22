class Solution {
public:
    string removeDuplicates(string s, int k) {
        int idx = 1, cnt = 1;
        
        while(idx < s.size()){
            if(s[idx] == s[idx-1]) cnt++;
            else cnt = 1;
            if(cnt == k){
                s.erase(s.begin()+idx-k+1,s.begin()+idx+1);
                idx = 1;
                cnt = 1;
            }
            else{
                idx++;
            }
            
        }
        return s;
    }
};

class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> st = {{'*',0}};
        string output;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == st[st.size()-1].first){
                int cnt = st[st.size()-1].second+1;
                if(cnt == k){
                    for(int tmp = 0 ; tmp < k-1 ; tmp++){
                        st.pop_back();
                    }
                }
                else{
                    st.push_back({s[i],cnt});
                }
            }
            else{
                st.push_back({s[i],1});
            }
        }
        for(int i=0 ; i<st.size() ; i++){
            output.push(st[i]);
        }
        return output;
    }
};