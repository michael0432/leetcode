#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int,int> map;
    int numTrees(int n) {
        if(n == 0) return 0;
        map[0] = 1;
        map[1] = 1;
        map[2] = 2;
        return numT(0,n);
    }
    int numT(int s, int e){
        if(map.count(e-s)){
            return map[e-s];
        }
        int cnt = 0;
        for(int i=s ; i<e ; i++){
            int left = numT(s,i);
            int right = numT(i+1,e);
            cnt += left*right;
        }
        map[e-s] = cnt;
        return cnt;
    }
};

int main(){
    int n = 1;
    Solution s;
    cout << s.numTrees(n) << endl;
}