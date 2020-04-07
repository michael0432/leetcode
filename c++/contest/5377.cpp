#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:

    string addOne(string s){
        bool flag = true;
        string out = s;
        for (int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '1'){
                out[i] = '0';
            }
            if(s[i] == '0'){
                flag = false;
                out[i] = '1';
                break;
            }
        }
        if(flag)
            out = "1" + out;
        return out;
    }
    string divideTwo(string s){
        string out = s;
        for (int i = s.size() - 1; i >= 1; i--){
            out[i] = out[i - 1];
        }
        out.erase(out.begin());
        return out;
    }

    int numSteps(string s) {
        int cnt = 0;
        while(s != "1"){
            if(s[s.size()-1] == '1'){
                s = addOne(s);
            }
            else{
                s = divideTwo(s);
            }
            cout << s << endl;
            cnt++;
        }
        return cnt;
    }
};

int main(){
    Solution so;
    cout << so.addOne("1101") << endl;
}