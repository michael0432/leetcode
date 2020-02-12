#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, bool> m;
    int numUniqueEmails(vector<string>& emails) {
        int cnt = 0;
        for(int i=0 ; i<emails.size() ; i++){
            string str = dealString(emails[i]);
            if(m.count(str) == 0){
                m[str] = true;
                cnt += 1;
            }
        }
        return cnt;
    }
    string dealString(string s){
        bool see_at = false;
        bool ignore_all = false;
        string new_s = "";
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == '@') see_at = true;
            if(!see_at){
                if(s[i] == '+'){
                    ignore_all = true;
                }
                else if(s[i] != '.' && !ignore_all){
                    new_s += s[i];
                }
            }
            else{
                new_s += s[i];
            }
        }
        return new_s;
    }
};