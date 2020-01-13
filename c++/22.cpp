#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution {
public:
    vector<string> result;
    vector<string> generateParenthesis(int n) {
        generation(n,n,n,"");
        return result;
    }
    void generation(int n, int left, int right, string s){

        if(left == 0 && right == 0){
            if(s.length() == n*2){
                result.push_back(s);
            }
            return;
        }

        if(left < 0 || right < 0){
            return;
        }

        if(right < left){
            return;
        }
        
        generation(n,left-1,right,s+"(");
        generation(n,left,right-1,s+")");
        return;
    }
};

int main(){
    int n = 3;
    Solution s;
    vector<string> r = s.generateParenthesis(n);

    for(int i=0 ; i<r.size() ; i++){
        cout << r[i] << endl;
    }
}