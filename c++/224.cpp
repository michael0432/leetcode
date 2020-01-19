#include <iostream>
#include <stack>
#include <ctype.h>
#include <string>
#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        vector<string> preorder_s = preorder(s);
        stack<string> st;
        for(int i=0 ; i<preorder_s.size() ; i++){
            cout << preorder_s[i] << " ";
        }

        cout << endl;
        for(int i=0 ; i<preorder_s.size() ; i++){
            if(preorder_s[i] == "+" || preorder_s[i] == "-" || preorder_s[i] == "*" || preorder_s[i] == "/"){
                int d1 = stoi(st.top());
                st.pop();
                int d2 = stoi(st.top());
                st.pop();
                cout << d1 << " " << d2 << " " <<  preorder_s[i] << endl;
                if(preorder_s[i] == "+") st.push(to_string(d1+d2));
                if(preorder_s[i] == "-") st.push(to_string(d2-d1));
                if(preorder_s[i] == "*") st.push(to_string(d1*d2));
                if(preorder_s[i] == "/") st.push(to_string(d2/d1));
            }
            else{
                st.push(preorder_s[i]);
            }
        }
        
        return stoi(st.top());
    }

    vector<string> preorder(string s){
        vector<string> out;
        stack<char> st;
        string dig = "";
        for(int i=0 ; i<s.length() ; i++){
            if(isdigit(s[i])){
                dig += s[i];
            }
            else if(s[i] == ' '){
                // do nothing;
            }
            else{
                out.push_back(dig);
                dig = "";
                if(s[i] == '+' || s[i] == '-'){
                    while(!st.empty()){
                        string ss(1,st.top());
                        out.push_back(ss);
                        st.pop();
                    }
                    st.push(s[i]);
                }
                else{
                    while(!st.empty() && (st.top() == '*' || st.top() == '/')){
                        string ss(1,st.top());
                        out.push_back(ss);
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
        if(dig != "") out.push_back(dig);
        while(!st.empty()){
            string ss(1,st.top());
            out.push_back(ss);
            st.pop();
        }
        return out;
    }
};

int main(){
    string fo = "1 + 3 - 5";
    Solution s;
    cout << s.calculate(fo) << endl;
}