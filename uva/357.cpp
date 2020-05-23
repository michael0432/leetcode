#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> all_m = {1, 5 , 10 ,25, 50};

int main(){

    vector<long long> v(30000);
    v[0] = 1;
    for (int i = 0; i < 5; i++){
        for (int j = all_m[i]; j <= 30000; j++){
            v[j] += v[j - all_m[i]];
        }
    }

    int n;
    while(cin >> n){
        if(v[n] == 1)
            cout << "There is only 1 way to produce " << n << " cents change." << endl;
        else
            cout << "There are " << v[n] << " ways to produce "  << n << " cents change." << endl;
    }
}