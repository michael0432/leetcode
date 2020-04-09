class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0)
            return false;
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map[nums[i]]++;
        }
            
        while(!map.empty()){
            int n = min_element(map.begin(), map.end())->first;
            for (int i = 0; i < k; i++){
                if(map[n] == 1)
                        map.erase(n);
                    else
                        map[n]--;
                if(i == k-1)
                    break;
                if(map.count(n+1) == 0)
                    return false;
                else{
                    n++;
                }
            }
        }
        return true;
    }
};