#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int minimum = INT_MAX;
        vector<vector<int>> out;
        sort(arr.begin(),arr.end());
        for(int i=1 ; i<arr.size() ; i++){
            minimum = min(arr[i]-arr[i-1], minimum);
        }
        for(int i=1 ; i<arr.size() ; i++){
            if(arr[i]-arr[i-1] == minimum){
                out.push_back({arr[i-1],arr[i]});
            }
        }
        return out;
    }
};