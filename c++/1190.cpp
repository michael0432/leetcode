class Solution {
public:

    string reverseParentheses(string s) {
        stack<string> st;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == ')'){
                string rev = "";
                while(!st.empty() && st.top() != "("){
                    rev += st.top();
                    st.pop();
                }
                st.pop();
                reverse(rev.begin(), rev.end());
                if(!st.empty() && st.top() != "(" && st.top() != ")"){
                    st.top() += rev;
                }
                else{
                    st.push(rev);
                }
                
            }
            else if(s[i] == '('){
                string ss(1,s[i]);
                st.push(ss);
            }
            else{
                if(!st.empty() && st.top() != "(" && st.top() != ")"){
                    st.top() += s[i];
                }
                else{
                    string ss(1,s[i]);
                    st.push(ss);
                }
            }
        }
        return st.top();
    }
};