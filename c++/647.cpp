#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        for(int i=0 ; i<s.size() ; i++){
            count += 1;
            int j = 1;
            while(i-j >=0 && i+j < s.size() && s[i-j] == s[i+j]){
                count += 1;
                j += 1;
            }
            if(i+1 < s.size() && s[i+1] == s[i]){
                count += 1;
                int j = 1;
                while(i-j >=0 && i+j+1 < s.size() && s[i-j] == s[i+j+1]){
                    count += 1;
                    j += 1;
                }
            }
        }
        return count;
    }
};

int main(){
    string str = "abc";
    Solution s;
    cout << s.countSubstrings(str) << endl;
}