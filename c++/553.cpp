#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        pair<float, string> p = max(nums);
        cout << p.first << " " << p.second << endl;
        return p.second;
    }

    string v2s(vector<int>& nums,bool front){
        if(front){
            string s = "";
            for(int i=0 ; i<nums.size() ; i++){
                s.append(to_string(nums[i]));
                if(i != nums.size()-1){
                    s.append("/");
                }
            }
            return s;
        }   
        else{
            string s = "(";
            for(int i=0 ; i<nums.size() ; i++){
                s.append(to_string(nums[i]));
                if(i != nums.size()-1){
                    s.append("/");
                }
            }
            s.append(")");
            return s;
        }
        
    }

    pair<float,string> max(vector<int>& nums){
        
        string s = v2s(nums, true);
        if(nums.size() == 1){
            pair<float, string> t1((float)nums[0],s);
            return t1;
        }
        else if(nums.size() == 2){
            pair<float, string> t1((float)nums[0]/(float)nums[1],s);
            return t1;
        }
        else{
            float output = nums[0];
            for(int i=1 ; i<nums.size() ; i++){
                output /= nums[i];
            }
            
            for(int i=1 ; i<nums.size() ; i++){
                vector<int> va, vb;
                for(int j=0 ; j<i ; j++){
                    va.push_back(nums[j]);
                }
                for(int j=i ; j<nums.size() ; j++){
                    vb.push_back(nums[j]);
                }
                // cout << max(va).first << " " << min(vb).first << endl;
                float tmp = max(va).first/min(vb).first;
                if(tmp > output){
                    output = tmp;
                    s = v2s(va, true) + "/" + v2s(vb,false);
                }
            }
            // cout << output << endl;
            pair<float, string> t1(output,s);
            return t1;
        }
    }
    pair<float,string> min(vector<int>& nums){
        string s = v2s(nums, true);
        if(nums.size() == 1){
            pair<float, string> t1((float)nums[0],s);
            return t1;
        }
        else if(nums.size() == 2){
            pair<float, string> t1((float)nums[0]/(float)nums[1],s);
            return t1;
        }
        else{
            float output = nums[0];
            for(int i=1 ; i<nums.size() ; i++){
                output /= nums[i];
            }
            for(int i=1 ; i<nums.size() ; i++){
                vector<int> va, vb;
                for(int j=0 ; j<i ; j++){
                    va.push_back(nums[j]);
                }
                for(int j=i ; j<nums.size() ; j++){
                    vb.push_back(nums[j]);
                }
                
                float tmp = min(va).first/max(vb).first;
                if(tmp < output){
                    output = tmp;
                    s = v2s(va, true) + "/" + v2s(vb,false);
                }
            }
            // cout << output << endl;
            pair<float, string> t1(output,s);
            return t1;
        }
    }
};

int main(){
    vector<int> nums = {300,1000,100,10,2};
    
    Solution s;
    s.optimalDivision(nums);
    // cout << s.magicalString(20) << endl;
}