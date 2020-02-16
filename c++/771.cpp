#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        unordered_map<char, bool> jmap;
        int cnt = 0;
        for (int i = 0; i < J.size(); i++){
            if(jmap.count(J[i]) == 0)
                jmap[J[i]] = true;
        }
        for (int i = 0; i < S.size(); i++){
            if(jmap.count(S[i]) != 0){
                cnt += 1;
            }
        }
        return cnt;
    }
};