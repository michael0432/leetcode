#include <iostream>
#include <vector>

using namespace std;

string solution(int n, int k, vector<int> v){
    int cnt = 0;
    for(int i=0 ; i<v.size() ; i++){
        if(v[i] <= 0) cnt += 1;
    }
    if(cnt >= k) return "NO";
    else return "YES";
}

int main(){
    int T;
    cin >> T;
    for(int i = 0; i < T; i++){
        int n,k;
        vector<int> v;
        cin >> n >> k;
        for(int i=0 ; i<n ; i++){
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        cout << solution(n,k,v) << endl;
    }
}