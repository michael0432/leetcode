#include <iostream>

using namespace std;

// class Solution {
// public:
//     int uniquePaths(int m, int n) {
//         double num = 1, denom = 1;
//         int small = m > n ? n : m;
//         for (int i = 1; i <= small - 1; ++i) {
//             num *= m + n - 1 - i;
//             denom *= i;
//         }
//         return (int)(num / denom);
//     }
// };

class Solution {
public:
    int uniquePaths(int m, int n) {
        m --;
        n --; 
        return c(m+n,n);
    }
    int c(int m, int n){
        double a = 1,b = 1;
        n = min(n,m-n);
        if(n == 0) return 1;
        double mm = (double)m;
        double nn = (double)n;
        for(int i = 1 ; i <= n ; i++){
            a = a*(double(i)+mm-nn)/(double)i;
            //b *= i;
        }
	    return (int)a;
    }
};

int main(){
    Solution s;
    int m = 50, n = 9;
    cout << s.uniquePaths(m,n) << endl;
}