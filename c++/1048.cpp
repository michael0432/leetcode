#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dp = {1};
    
    int longestStrChain(vector<string>& words) {
        for(int i=1 ; i<words.size() ; i++){
            if(ispredecessor(words[i-1], words[i])){
                dp[i] = dp[i-1]+1;
            }
            else{
                
            }
        }
    }
    bool ispredecessor(string s1, string s2){

    }
};

int main(){

}