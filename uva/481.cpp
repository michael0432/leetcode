#include <iostream>
#include <vector>

using namespace std;

void trace(int i, vector<int>& v, vector<int>& mem){
    if(mem[i] != -1)
        trace(mem[i], v, mem);
    cout << v[i] << endl;
}


int main(){
    int n;
    vector<int> v;
    vector<int> lis;
    
    while(cin >> n){
        v.push_back(n);
    }

    vector<int> pos(v.size());

    lis.push_back(v[0]);
    pos[0] = 0;

    for (int i = 1; i < v.size(); i++){
        if(v[i] > lis.back()){
            lis.push_back(v[i]);
            pos[i] = lis.size() - 1;
        } 
        else{
            auto it = lower_bound(lis.begin(), lis.end(), v[i]);
            *lower_bound(lis.begin(), lis.end(), v[i]) = v[i];
            pos[i] = it - lis.begin();
            //cout << pos[i] << endl;
        }
        
    }

    cout << lis.size() << endl;
    cout << "-" << endl;
    vector<int> output;
    int fpos = lis.size() - 1;
    for (int i = v.size() - 1; i >= 0 && fpos >= 0; i--){
        if(pos[i] == fpos){
            output.push_back(v[i]);
            fpos--;
        }
    }
    for (int i = lis.size()-1; i >= 0; i--){
        cout << output[i] << endl;
    }
}