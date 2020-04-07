class Solution {
public:
    vector<vector<vector<int>>> dp;
    int cal(int a, int b, char c){
        if(c == '+')
            return a + b;
        else if(c == '-')
            return a - b;
        else
            return a * b;
    }

    vector<int> dfs(vector<int>& nums, vector<char>& pats, int sid, int eid){
        
        if(sid > eid)
            return {};
        if(sid == eid) return {nums[sid]};
        if(sid == eid - 1)
            return {cal(nums[sid], nums[eid], pats[sid])};
        if(!dp[sid][eid].empty())
            return dp[sid][eid];
        vector<int> output;
        for (int i = sid; i < eid; i++){
            auto left = dfs(nums, pats, sid, i);
            auto right = dfs(nums, pats, i+1, eid);
            //cout << i << " " << left.size() << " " << right.size() << endl;
            for(auto a : left){
                for(auto b: right){
                    //cout << a << " " << b << endl;
                    output.push_back(cal(a, b, pats[i]));
                }
            }
        }
        dp[sid][eid] = output;
        return output;
    }

    vector<int> diffWaysToCompute(string input) {
        if(input.size() == 0)
            return {};
        vector<int> nums;
        vector<char> pats;
        string s;
        
        for (int i = 0; i < input.size(); i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                pats.push_back(input[i]);
                nums.push_back(stoi(s));
                s = "";
            }
            else{
                s += input[i];
            }
        }
        nums.push_back(stoi(s));
        dp.resize(nums.size(), vector<vector<int>>(nums.size(), vector<int>()));
        return dfs(nums, pats, 0, nums.size() - 1);
    }
};