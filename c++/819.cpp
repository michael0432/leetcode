#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <iterator>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        int max_appear_num = 0;
        unordered_map<string, int> map;
        unordered_map<string, bool> banned_map;
        // cut string
        stringstream ss(paragraph);
        istream_iterator<string> begin(ss);
        istream_iterator<string> end;
        vector<string> vstrings(begin, end);
        // banned map
        for (int i = 0; i < banned.size(); i++){
            if(banned_map.count(banned[i]) == 0)
                banned_map[banned[i]] = true;
        }
        // count paragraph
        for (int i = 0; i < vstrings.size(); i++){
            if(banned_map.count(vstrings[i]) == 0){
                if(map.count(vstrings[i]) == 0){
                    map[vstrings[i]] = 1;
                }
                else{
                    map[vstrings[i]] += 1;
                }
                max_appear_num = max(max_appear_num, map[vstrings[i]]);
            }
        }
        // find max
        
    }
};