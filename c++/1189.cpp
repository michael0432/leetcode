#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(int i=0 ; i<text.length() ; i++){
            if(m.count(text[i]) == 0){
                m[text[i]] = 1;
            }
            else{
                m[text[i]] += 1;
            }
        }
        //return min(m[b],m[a],m[l]/2,m[o]/2,m[n]);
        return min(m['b'], min(m['a'], min(m['l']/2, min(m['o']/2, m['n']))));
    }
};