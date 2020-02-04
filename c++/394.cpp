#include <stack>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string now_s;
        
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '['){
                st.push(now_s);
                now_s = "";
                st.push("[");
            }
            else if(s[i] == ']'){
                st.push(now_s);
                now_s = "";
                string repeat_s = "";
                
                vector<string> v_s;
                while(st.top() != "["){
                    v_s.push_back(st.top());
                    //repeat_s += st.top();
                    st.pop();
                }
                for(int i=v_s.size()-1 ; i>=0 ; i--)
                    repeat_s += v_s[i];
                // reverse(repeat_s.begin(),repeat_s.end());
                st.pop();
                int repeat_time = stoi(st.top());
                st.pop();
                string tmp_s = repeat_s;
                for(int i=0 ; i<repeat_time-1 ; i++){
                    repeat_s += tmp_s;
                }
                st.push(repeat_s);
            }
            else if(isdigit(s[i])){
                if(i-1 >= 0 && !isdigit(s[i-1]) && now_s != ""){
                    st.push(now_s);
                    now_s = "";
                }
                now_s += s[i];
            }
            else{
                if(i-1 >= 0 && isdigit(s[i-1]) && now_s != ""){
                    st.push(now_s);
                    now_s = "";
                }
                now_s += s[i];
            }
        }
        
        string out_s = "";
        vector<string> v_s;
        while(!st.empty()){
            v_s.push_back(st.top());
            st.pop();
        }
        for(int i=v_s.size()-1 ; i>=0 ; i--)
            out_s += v_s[i];
        out_s += now_s;
        return out_s;
    }
};

int main(){
    string str = "2[abc]3[cd]ef";
    Solution s;
    cout << s.decodeString(str) << endl;
}