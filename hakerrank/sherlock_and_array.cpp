#include <iostream>
#include <vector>

using namespace std;

string solution(vector<int>& v){
    vector<int> sum;
    int total = 0;
    for(int i=0 ; i<v.size() ; i++){
        total += v[i];
        sum.push_back(total);
    }
    for(int i=0 ; i<v.size() ; i++){
        int left = 0;
        if(i != 0) left = sum[i-1];
        int right = total - sum[i];
        if(left == right) return "YES";
    }
    return "NO";
}

int main(){
    vector<int> v;
    int T, n;
    cin >> T;
    for(int i=0 ; i<T ; i++){
        cin >> n;
        for(int j=0 ; j<n ; j++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        cout << solution(v) << endl;
        v.clear();
    }
}