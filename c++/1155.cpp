#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Solution {
public:
    typedef pair<int,int> key;
    map<key,int> m;
    int numRollsToTarget(int d, int f, int target) {
        if(d == 1){
            if(target > f) return 0;
            else return 1;
        }
        else{
            int cnt = 0;
            key k = make_pair(d,target);
            if(m.count(k) == 0){
                for(int i=1 ; i<=f ; i++){
                    if(target-i <= 0) break;
                    cnt = (cnt + numRollsToTarget(d-1, f, target-i) % 1000000007) % 1000000007;
                    
                }
                m[k] = cnt;
            }
            else cnt = m[k];
            return cnt % 1000000007;
        } 
    }
};

int main(){
    int d = 30;
    int f = 30;
    int target = 500;
    Solution s;
    cout << s.numRollsToTarget(d, f, target) << endl;
}