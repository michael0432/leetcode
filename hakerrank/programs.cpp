#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string solution(string s){
    unordered_map<char, int> map;
    int cnt = 0;
    for(int i=0 ; i<s.size() ; i++){
        char c = tolower(s[i]);
        if(c != ' '){
            if(!map.count(c)){
                map[c] = 1;
                cnt ++;
            }
        }
    }
    if(cnt == 26) return "pangram";
    else return "not pangram";
}

int main(){
    string s_in;
    getline(cin, s_in);
    cout << solution(s_in);
}