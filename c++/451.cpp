#include<iostream>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char,int> m;
    string frequencySort(string s) {
        
        for(int i=0 ; i<s.length() ; i++){
            if(m.count(s[i]) == 0) m[s[i]] = 1;
            else m[s[i]] += 1;
        }
        sort(s.begin() ,s.end(), [this] (char a, char b){return sortf(a,b);});
        return s;
    }
    bool sortf(char a, char b){
        if(m[a] > m[b]) return true;
        if(m[a] < m[b]) return false;
        return a>b;
    }
};

int main(){
    string str = "aaAbBb";
    Solution s;
    cout << s.frequencySort(str);
}