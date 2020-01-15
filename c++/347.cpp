#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        vector<int> sort_num;
        vector<int> output;
        for(int i=0 ; i<nums.size() ; i++){
            if(map.count(nums[i]) != 0){
                map[nums[i]] += 1;
            }
            else{
                map[nums[i]] = 1;
            }
        }
        unordered_map<int,int>::iterator it = map.begin();
        while(it != map.end()){
            sort_num.push_back(it->second);
            it++;
        }
        sort(sort_num.begin(),sort_num.end(),greater<int>());
        int threshold = sort_num[k-1];
        it = map.begin();
        
        while(it != map.end()){
            if(it->second >= threshold)
                output.push_back(it->first);
            it++;
        }
        return output;
    }
};

int main(){
    vector<int> nums = {1};
    int k = 1;
    Solution s;
    vector<int> out = s.topKFrequent(nums, k);
    for(int i=0 ; i<out.size() ; i++){
        cout << out[i] << " ";
    }
}