#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cases;
    cin >> cases;
    for (int x = 0; x < cases; x++){
        int m, n;
        cin >> m >> n;
        vector<int> all_coin(n);
        vector<int> number(10001, INT_MAX);
        number[0] = 0;
        for (int y = 0; y < n; y++){
            cin >> all_coin[y];
        }
        for (int i = 0; i < n; i++){
            for (int j = 10000; j >= all_coin[i]; j--){
                if(number[j - all_coin[i]] != INT_MAX){
                    number[j] = min(number[j],number[j - all_coin[i]] + 1);
                }
            }
        }
        for (int i = m; i <= 10000; i++){
            if(number[i] != INT_MAX){
                cout << i << endl << number[i] << endl;
                break;
            }
        }
    }
}