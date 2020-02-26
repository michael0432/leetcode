#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int solution(int k, vector<int> v){
    int maxi = INT_MIN;
    for(int i=0 ; i<v.size() ; i++){
        maxi = max(v[i], maxi);
    }
    return max(maxi-k,0);
}

int main(){
    int n, k;
    vector<int> v;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << solution(k, v);
}