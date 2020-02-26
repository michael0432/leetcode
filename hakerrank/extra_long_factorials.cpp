#include <iostream>
#include <vector>

using namespace std;

class BigInt{
public:
    BigInt(int digit_num, vector<int> nums){
        this->digit_num = digit_num;
        this->nums = nums;
    }
    int digit_num;
    vector<int> nums;
};

BigInt mul(BigInt a, BigInt b){
    int idx = 0;
    int cnt = 0;
    vector<int> v;
    BigInt out(0,v);
    for(int i=0 ; i<b.digit_num ; i++){
        for(int j=0 ; j<a.digit_num ; j++){
            out[i] += a[j] * b[i] + cnt;
        }
    }
}