#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string out = "";
        for(int i=0 ; i <address.size() ; i++){
            if(address[i] == '.'){
                out += "[.]";
            }
            else{
                out += address[i];
            }
        }
        return out;
    }
};