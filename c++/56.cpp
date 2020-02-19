#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    struct sort_v{
        inline bool operator() (const vector<int>& struct1, const vector<int>& struct2)
        {
            return (struct1[1] < struct2[1]);
        }
    };
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), sort_v());
        for(int i=0 ; i<intervals.size() ; i++){
            cout << intervals[i][0] << " " << intervals[i][1] << endl;
        }
        stack<vector<int>> st;
        vector<vector<int>> output;
        for(int i=0 ; i<intervals.size() ; i++){
            if(!st.empty()){
                vector<int> now_interval = intervals[i];
                while(!st.empty() && st.top()[1] >= now_interval[0]){
                    // merge
                    int min_value = min(st.top()[0], now_interval[0]);
                    int max_value = now_interval[1];
                    st.pop();
                    now_interval = {min_value, max_value};
                }
                st.push(now_interval);
            }
            else{
                st.push(intervals[i]);
            }
        }
        while(!st.empty()){
            output.push_back(st.top());
            st.pop();
        }
        return output;
    }
};