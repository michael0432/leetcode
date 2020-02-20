#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestSubstring(string s, int k) {
        return finds(s, k, 0, s.size()-1);
    }
    int finds(string s, int k, int sid, int eid){
        unordered_map<char, int> m;
        //cout << sid << " " << eid << endl;
        if(sid > eid) return 0;
        if(sid == eid){
            if(k > 1) return 0;
            else return 1;
        }
        for(int i=sid ; i<=eid ; i++){
            if(!m.count(s[i])){
                m[s[i]] = 1;
            }
            else{
                m[s[i]] += 1;
            }
        }
        char num = '-';
        for(auto it = m.begin() ; it != m.end() ; it++){
            if(it->second < k){
                num = it->first;
                break;
            }
        }
        if(num != '-'){
            auto it = find(s.begin()+sid, s.begin()+eid+1, num);
            return max(finds(s, k, sid, it-s.begin()-1), finds(s, k, it-s.begin()+1, eid));
        }
        else{
            return eid-sid+1;
        }
    }
};