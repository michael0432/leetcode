#include <iostream>
#include <vector>

using namespace std;

int solution(int n){
    int digit = 0;
    int tmp_n = n;
    while(tmp_n > 0){
        tmp_n /= 10;
        digit++;
    }
    for(int i=n-digit*10 ; i<n ; i++){
        
        int tmp = i;
        int sum = i;
        while(tmp > 0){
            sum += tmp % 10;
            //digit.push_back(tmp % 10);
            tmp /= 10;
        }
        if(sum == n){
            return i;
        }
    }
    return 0;
}

int main(){
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int tmp;
        cin >> tmp;
        cout << solution(tmp) << endl;
    }
}