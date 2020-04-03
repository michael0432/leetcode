#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<vector<int>> greedy(vector<int>& v){
    unordered_map<int, int> m;
    
    int cnt_max = 0;
    for (int i = 0; i < v.size(); i++){
        if(m.count(v[i])) 
            m[v[i]]++;
        else
            m[v[i]] = 1;
        cnt_max = max(cnt_max, m[v[i]]);
    }
    
    vector<vector<int>> output(cnt_max, vector<int>(0));
    for (int i = 0; i < v.size(); i++){
        output[i % cnt_max].push_back(v[i]);
    }
    return output;
}

int main(){
    int n;
    vector<int> v;
    while(cin >> n && n != 0){
        for (int i = 0; i < n; i++){
            int x;
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        vector<vector<int>> v_out = greedy(v);
        cout << v_out.size() << endl;
        for (int x = 0; x < v_out.size(); x++){
            for (int y = 0; y < v_out[x].size(); y++){
                cout << v_out[x][y];
                if(y != v_out[x].size()-1)
                    cout << " ";
            }
            cout << endl;
        }
    }
}