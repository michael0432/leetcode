class Solution {
public:

    bool isValid(int i, int j, int k){
        return i + j > k;
    }

    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            for (int j = i + 1; j < nums.size(); j++){
                for (int k = nums.size()-1; k > j; k++){
                    if(isValid(nums[i], nums[j], nums[k]){
                        cnt += k-j;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};