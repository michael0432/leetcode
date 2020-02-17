#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        return predict(nums, 0, 0, 0, nums.size() - 1, true);
    }
    // true : p1 win
    bool predict(vector<int>& nums, int p1_score, int p2_score, int sid, int eid, bool who){
        
        if(sid == eid){
            if(who)
                return p1_score + nums[sid] >= p2_score;
            return p1_score >= p2_score + nums[sid];
        }
        if(who){
            // p1
            bool b1 = predict(nums, p1_score + nums[sid], p2_score, sid+1, eid, !who);
            bool b2 = predict(nums, p1_score + nums[eid], p2_score, sid, eid-1, !who);
            if(b1 || b2)
                return true;
            return false;
        }
        else{
            // p2
            bool b1 = predict(nums, p1_score, p2_score + nums[sid], sid+1, eid, !who);
            bool b2 = predict(nums, p1_score, p2_score + nums[eid], sid, eid-1, !who);
            if(!b1 || !b2)
                return false;
            return true;
        }
    }
};