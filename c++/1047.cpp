#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        string out = "";
        for (int i = 0; i < S.size(); i++){
            if(!st.empty() && st.top() == S[i]){
                st.pop();
            }
            else{
                st.push(S[i]);
            }
        }
        while(!st.empty()){
            out = st.top() + out;
            st.pop();
        }
        return out;
    }
};