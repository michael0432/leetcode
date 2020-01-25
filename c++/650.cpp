#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int minSteps(int n) {
        int now_num = 1;
        int cmd = 0;
        int copy_num = 0;
        bool copy_flag = false;
        while(now_num < n){
            if((n - now_num) % now_num == 0 && copy_flag == false){
                // copy
                copy_num = now_num;
                copy_flag = true;
            }
            else{
                // paste
                now_num += copy_num;
                copy_flag = false;
            }
            cmd += 1;
        }
        return cmd;
    }
};

int main(){
    int n = 3;
    Solution s;
    cout << s.minSteps(n);
}