#include<string>
#include<ctype.h>
#include<algorithm>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        string output = S;
        int sid = 0, eid = S.size()-1;
        for(int i = 0 ; i<S.size() ; i++){
            while(!isalpha(S[eid])){
                eid --;
                if(eid < 0) break;
            } 
            if(sid >= eid) break;
            if(isalpha(S[i])){ 
                swap(output[sid],output[eid]);
                sid ++;
                eid --;
            }
            else{
                sid++;
            }
        }
        return output;
    }
};