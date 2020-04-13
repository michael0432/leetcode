class Solution {
public:
    

    int dfs(vector<int>& nums, vector<int>& mem, int idx){
        if(idx == nums.size()-1)
            return 0;
        if(mem[idx] != -1)
            return mem[idx];
        int minjump = INT_MAX;
        for (int i = 1; i <= nums[idx]; i++){
            if(idx + i < nums.size()){
                minjump = min(minjump, dfs(nums, mem, idx + i));
            }
        }
        if(minjump != INT_MAX) 
            mem[idx] = minjump + 1;
        else
            mem[idx] = INT_MAX;
        return mem[idx];
    }

    int jump(vector<int>& nums) {
        vector<int> mem(nums.size(), -1);
        return dfs(nums, mem, 0);
    }
};


class Solution {
public:
    int jump(vector<int>& nums) {
        int prepos = 0, farpos = 0, cnt = 0, nowpos = 0;
        while(farpos < nums.size()-1){
            cnt++;
            prepos = farpos;
            while(nowpos <= prepos){
                farpos = max(farpos, nowpos + nums[nowpos]);
                nowpos++;
            }
        }
        return cnt;
    }
};