#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int,unordered_map<int,int>> map;
        map[A[1]-A[0]][1] = 2;
        int max = 2;
        for(int i=2 ; i<A.size() ; i++){
            for(int j=0 ; j<i ; j++){
                if(map.count(A[i] - A[j]) == 0){
                    map[A[i] - A[j]][i] = 2;
                }
                else{
                    if(map[A[i] - A[j]].count(j) == 0) map[A[i] - A[j]][i] = 2;
                    else map[A[i] - A[j]][i] = map[A[i] - A[j]][j] + 1;
                } 
                if(map[A[i] - A[j]][i] > max) max = map[A[i] - A[j]][i];
            }
        }
        return max;
    }
};

int main(){
    vector<int> n = {12,28,13,6,34,36,53,24,29,2,23,0,22,25,53,34,23,50,35,43,53,11,48,56,44,53,31,6,31,57,46,6,17,42,48,28,5,24,0,14,43,12,21,6,30,37,16,56,19,45,51,10,22,38,39,23,8,29,60,18};
    Solution s;
    cout << s.longestArithSeqLength(n) << endl;
}