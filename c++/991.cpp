#include <iostream>

using namespace std;

class Solution {
public:
    int brokenCalc(int X, int Y) {
        int cmd = 0;
        if(Y < X) return X-Y;
        while(Y > X){
            cmd += 1;
            if(Y % 2 == 1){
                Y = Y+1;
                cmd += 1;
            }
            Y = Y / 2;
        }
        return cmd + X - Y;
    }
};

int main(){
    int x = 2;
    int y = 3;
    Solution s;
    cout << s.brokenCalc(x,y) << endl;
}