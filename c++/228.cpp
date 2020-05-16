class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<int> tmp = {nums[0]};
        vector<string> output;
        for (int i = 1; i < nums.size(); i++){
            if(nums[i] - nums[i-1] == 1){
                tmp.push_back(nums[i]);
            }
            else{
                if(tmp.size() == 1)
                    output.push_back(to_string(tmp[0]));
                else
                    output.push_back(to_string(tmp[0])+"->"+to_string(tmp.back()));
                tmp = {nums[i]};
            }
        }
        if(tmp.size() == 1)
            output.push_back(to_string(tmp[0]));
        else
            output.push_back(to_string(tmp[0])+"->"+to_string(tmp.back()));
        return output;
    }
};