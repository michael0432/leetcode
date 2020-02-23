#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> v){
    sort(v.begin(), v.end());
    int maxi = 1;
    for(int i=0 ; i<v.size() ; i++){
        int cnt = 1;
        for(int j=i+1 ; j<v.size() ; j++){
            if(v[j] - v[i] <= 1){
                cnt += 1;
            }
            else{
                break;
            }
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}

int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << solution(v);
    return 0;
}