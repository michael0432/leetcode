#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(maxChoosableInteger >= desiredTotal) return true;
        if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal) return false;
        unordered_map<int, bool> m;
        return WinorNot(maxChoosableInteger, desiredTotal,0, m);
    }
    bool WinorNot(int maxChoosableInteger, int desiredTotal, int used, unordered_map<int, bool>& m){
        if(m.count(used)) return m[used];
        
        for(int i=0 ; i < maxChoosableInteger ; i++){
            int x = (1<<i);
            if((x & used) == 0){

                if(desiredTotal <= i+1 || !WinorNot(maxChoosableInteger, desiredTotal-i-1, x|used, m)){
                   m[used] = true;
                   return true; 
                }
            }

        }
        m[used] = false;
        return false;
        
    }
};

int main(){
    int max = 10;
    int desired = 11;
    Solution s;
    cout << s.canIWin(max, desired) << endl;
}