#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int solution(vector<int> v1, vector<int> v2){
    int max_v1 = 0;
    int max_v2 = 0;
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    for(int i=0 ; i<v1.size() ; i++){
        if(find(v2.begin(), v2.end(), v1[i]) == v2.end() && m1.count(v1[i]) == 0){
            m1[v1[i]] = 1;
            max_v1 += 1;
        }
    }
    for(int i=0 ; i<v2.size() ; i++){
        if(find(v1.begin(), v1.end(), v2[i]) == v1.end() && m2.count(v2[i]) == 0){
            m2[v2[i]] = 1;
            max_v2 += 1;
        }
    }
    return min(max_v1, max_v2);
}

int main(){
    while(1){
        int n, m;
        vector<int> v1;
        vector<int> v2;
        cin >> n >> m;
        if(n == 0 && m == 0){
            break;
        }
        else{
            for(int i=0 ; i<n ; i++){
                int tmp;
                cin >> tmp;
                v1.push_back(tmp);
            }
            for(int i=0 ; i<m ; i++){
                int tmp;
                cin >> tmp;
                v2.push_back(tmp);
            }
            cout << solution(v1, v2) << endl;
        }
    }
    
}