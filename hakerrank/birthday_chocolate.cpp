#include <iostream>
#include <vector>

using namespace std;

int solution(int d, int m, vector<int> v){
    int cnt = 0;
    for(int i=0 ; i<v.size()-m+1 ; i++){
        int sum = 0;
        for(int j=0 ; j<m ; j++){
            sum += v[i+j];
        }
        if(sum == d) cnt += 1;
    }
    return cnt;
}

int main(){
    int n, d, m;
    vector<int> v;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int tmp;
        cin>>tmp;
        v.push_back(tmp);
    }
    cin >> d >> m;
    cout << solution(d, m, v);
}