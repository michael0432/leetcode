#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        k -= 1;
        vector<int> all_n;
        for(int i=1 ; i<=n ; i++){
            all_n.push_back(i);
        }

        string out = "";
        while(all_n.size() > 0){
            int cross_n = cross(all_n.size()-1);
            int idx = (k / cross_n);
            out += to_string(all_n[idx]);
            k -= idx * cross_n;
            // cout << k << endl;
            all_n.erase(all_n.begin()+idx);
            // (k / cross(n-1)) + 1;
        }
        return out;
    }
    int cross(int m){
        int out = 1;
        for(int i=m ; i>=1 ; i--){
            out *= i;
        }
        return out;
    }
};

int main(){
    int n = 4;
    int k = 9;
    Solution s;
    cout << s.getPermutation(n,k) << endl;
    
}