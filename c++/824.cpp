#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    string toGoatLatin(string S) {
        int idx = 1;
        string output = "";
        string tmp = "";
        for(int i=0 ; i < S.size() ; i++){
            if(S[i] == ' '){
                // add tmp
                output += tmp;
                // add ma
                output += "ma";
                // add a
                for(int i=0 ; i<idx ; i++){
                    output += "a";
                }
                idx += 1;
                output += S[i];
                tmp = "";
            }
            else if(i == 0 || S[i-1] == ' '){
                // first word
                if(!(S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u' || S[i] == 'A' || S[i] == 'E' || S[i] == 'I' || S[i] == 'O' || S[i] == 'U')){
                    tmp += S[i];
                }
                else{
                    output += S[i];
                }
            }
            else{
                output += S[i];
            }
            if(i == S.size()-1){
                // add tmp
                output += tmp;
                // add ma
                output += "ma";
                // add a
                for(int i=0 ; i<idx ; i++){
                    output += "a";
                }
            }
        }
        return output;
    }
};