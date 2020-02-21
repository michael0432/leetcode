#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;
        for(int i=0 ; i<tokens.size() ; i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ){
                int second_num = stoi(st.top());
                st.pop();
                int first_num = stoi(st.top());
                st.pop();
                if(tokens[i] == "+"){
                    st.push(to_string(first_num+second_num));
                }
                if(tokens[i] == "-"){
                    st.push(to_string(first_num-second_num));
                }
                if(tokens[i] == "*"){
                    st.push(to_string(first_num*second_num));
                }
                if(tokens[i] == "/"){
                    st.push(to_string(first_num/second_num));
                }
            }
            else{
                st.push(tokens[i]);
            }
        }
        return stoi(st.top());
    }
};