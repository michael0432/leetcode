#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> v;
        v.push_back(0);
        for(int i=1 ; i<=num ; i++){
            if(i % 2 == 0){
                v.push_back(v[i/2]);
            }
            else{
                v.push_back(v[i-1]+1);
            }
        }
        return v;
        
    }
};

int main(){
    int n = 10;
    
    Solution s;
    vector<int> v = s.countBits(n);
    for(int i=0 ; i<v.size() ; i++){
        cout << v[i] << " ";
    }
    cout << endl;
}