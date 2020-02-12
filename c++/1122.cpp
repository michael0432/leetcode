#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v;
        vector<int> arr1_copy = arr1;
        for(int i=0 ; i<arr2.size() ; i++){
            for(int j=0 ; j<arr1.size() ; j++){
                if(arr1[j] == arr2[i]){
                    v.push_back(arr1[j]);
                    arr1_copy[j] = INT_MIN;
                }
            }
        }
        sort(arr1_copy.begin(), arr1_copy.end());
        for(int i=0 ; i<arr1_copy.size() ; i++){
            if(arr1_copy[i] != INT_MIN) v.push_back(arr1_copy[i]);
        }
        return v;
    }
};