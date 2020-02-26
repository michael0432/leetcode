#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int>& v, string s){
    int height = 0;
    for(int i=0 ; i<s.size() ; i++){
        int c = s[i] - 'a';
        height = max(height, v[c]);
    }
    return height * s.size();
}

int main(){
    vector<int> v;
    string s;
    for(int i=0 ; i<26 ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cin >> s;
    cout << solution(v, s);
}