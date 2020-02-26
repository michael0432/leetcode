#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits.h>
using namespace std;

int solution(vector<int> v){
    unordered_map<int, int> m;
    int max_num = INT_MIN;
    int ans = 0;
    for(int i=0 ; i<v.size() ; i++){
        if(!m.count(v[i])){
            m[v[i]] = 1;
        }
        else{
            m[v[i]] += 1;
            max_num = max(m[v[i]], max_num);
        }
    }
    int min_id = INT16_MAX;
    for(auto it = m.begin() ; it != m.end() ; it++){
        if(it->second == max_num){
            if(it->first < min_id){
                min_id = it->first;
                ans = it->first;
            }  
        }
    }
    return ans;
}

int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    cout << solution(v);
}