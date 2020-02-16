#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

class Solution {
public:
    bool detectCapitalUse(string word) {
        int big_num = 0;
        bool first_big = false;
        
        for (int i = 0; i < word.size(); i++){
            if(isupper(word[i])){
                big_num += 1;
                if(i == 0) 
                    first_big = true;
            }
        }
        if(big_num == word.size())
            return true;
        else if(big_num == 1 && first_big)
            return true;
        else if(big_num == 0)
            return true;
        else
            return false;
    }
};