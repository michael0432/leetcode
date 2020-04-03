class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++){
            if(m.count(nums[i]) == 0)
                m[nums[i]] = 1;
            else if(m.count(nums[i]) == 1)
                m[nums[i]] = 2;
        }
        for (auto it = m.begin(); it != m.end(); it++){
            if(it->second == 1)
                return it->first;
        }
        return 0;
    }
};