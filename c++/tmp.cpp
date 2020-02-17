
// & and 
// | or 
// ^ xor
#include <iostream>

using namespace std;


int main(){
    int a = 3;    // 0000000000000000000000011

    // 00000000...000000011
    // 00000000000000001000
    // 10000000000000000000
    // if (& == 0) -> 這位數是0
    // else -> 這位數是1

    int b = 2; 
    int c = a ^ b;
    //cout << (a<<5) << endl;


    int cnt = 0;
    for(int i = 0 ; i < 32 ; i++){
        if((a & (1<<i))){
            cnt += 1;
        }
    }
    cout << cnt << endl;
}
