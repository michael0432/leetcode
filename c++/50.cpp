#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        if(n == 1) return x;
        if(n == -1) return 1/x;
        if(n % 2 == 0){
            double val = myPow(x,n/2);
            return val * val;
        }
        if(n % 2 == 1){
            double val = myPow(x,n/2);
            return val * val * x;
        } 
        if(n % 2 == -1){
            double val = myPow(x,n/2);
            return val * val * (1/x);
        } 
        return 1;
    }
};

int main(){
    double x = 0.00001;
    int n = 2147483647;

    Solution s;
    cout << s.myPow(x,n) << endl;
}