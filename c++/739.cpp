#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        unordered_map<int,int> map = {{T[T.size()-1],T.size()-1}};
        vector<int> out;
        out.push_back(0);
        for(int i=T.size()-2 ; i>=0 ; i--){
            int min_dis = INT32_MAX;
            for(auto j = map.begin() ; j != map.end() ; j++){
                if(j->first > T[i]){
                    if(j->second - i < min_dis){
                        min_dis = j->second - i;
                    }
                }
            }
            if(min_dis == INT32_MAX){
                min_dis = 0;
            }
            map[T[i]] = i;
            out.push_back(min_dis);
            
        }
        reverse(out.begin(),out.end());
        return out;
    }
};

int main(){
    Solution s;
    vector<int> T = {73, 74, 75, 71, 69, 72, 76, 73};

    vector<int> out = s.dailyTemperatures(T);
    for(int i=0 ; i<out.size() ; i++){
        cout << out[i] << " ";
    }
    
}

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> s;
        vector<int> ans(T.size());
        for (int i = 0; i < T.size(); i++){
            while(!s.empty() && T[i] > T[s.top()]){
                ans[s.top()] = i - s.top();
                s.pop();
            }
            s.push(i);
        }
        return ans;
    }
};