#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int cnt = 0;
        int digit = 0;
        for(int i=s.size()-1 ; i>= 0 ; i--, digit++){
            cnt += chartoint(s[i]) * (pow(26,digit));
        }
        return cnt;
    }
    int chartoint(char c){
        return c-'A'+1;
    }
};