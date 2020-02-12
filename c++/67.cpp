#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        int digit = 0;
        int carry = 0;
        string out_s = "";
        while(digit < a.length() || digit < b.length()){
            int o;
            if(a.length()-1 >= digit && b.length()-1 >= digit){
                o = c2i(a[a.length()-1-digit]) + c2i(b[b.length()-1-digit]) + carry;
            }
            else if(a.length()-1 >= digit){
                o = c2i(a[a.length()-1-digit]) + carry;
            }
            else if(b.length()-1 >= digit){
                o = c2i(b[b.length()-1-digit]) + carry;
            }
            if(o > 1){
                o -= 2;
                carry = 1;
            }
            else{
                carry = 0;
            }
            out_s = to_string(o) + out_s;
            digit += 1;
            
        }
        if(carry != 0) out_s = "1"+out_s;
        return out_s;
    }
    int c2i(char c){
        int i = c - '0';
        return i;
    }
};