#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> power2;
    bool reorderedPowerOf2(int N) {
        int cnt = 1;
        for(int i=0 ; i<32 ; i++){
            int p2 = cnt<<i;
            vector<int> empty_v;
            power2.push_back(empty_v);
            for( ; p2>0; p2/=10){
                power2[i].push_back(p2%10);
            }
            sort(power2[i].begin(),power2[i].end());
        }
        vector<int> n_v;
        for( ; N>0; N/=10){
            n_v.push_back(N%10);
        }
        sort(n_v.begin(),n_v.end());
        for(int i=0 ; i<32 ; i++){
            bool b = false;
            cout << endl;
            if(power2[i].size() == n_v.size()){
                for(int j=0 ; j<power2[i].size() ; j++){
                    if(power2[i][j] != n_v[j]){
                        b = false;
                        break;
                    }
                    b = true;
                }
                if(b){
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    int n = 2104;
    
    Solution s;
    cout << s.reorderedPowerOf2(n) << endl;
    
}