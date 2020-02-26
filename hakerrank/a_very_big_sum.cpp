#include <iostream>

using namespace std;

int main(){
    int n;
    long long int input_num;
    long long int sums = 0;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> input_num;
        sums += input_num;
    }
    cout << sums;
}