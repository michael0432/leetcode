#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> v;
        for(int i=left ; i<=right ; i++){
            int num = i;
            bool b = true;
            while(num >= 1){
                
                int div_num = num % 10;
                if(div_num == 0){
                    b = false;
                    break;
                }
                else if(i % div_num != 0){
                    b = false;
                    break;
                }
                num -= div_num;
                num /= 10;
            }
            if(b) v.push_back(i);
        }
        return v;
    }
};