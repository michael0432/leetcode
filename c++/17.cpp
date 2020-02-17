#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> output;
    vector<string> mapping = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0) return {};
        combine(digits, mapping, "");
        return output;
    }
    void combine(string digits, vector<string>& mapping, string now_s){
        if(digits.length() == 0){
            output.push_back(now_s);
            return;
        } 
        else{
            int num = ctoi(digits[0]);
            digits.erase(digits.begin());
            for(int i=0 ; i<mapping[num].length() ; i++){
                string add_str(1, mapping[num][i]);
                combine(digits, mapping, now_s+add_str);
            }
        }
    }
    int ctoi(char c){
        return (int)c-'0';
    }
};