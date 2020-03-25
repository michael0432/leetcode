class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int i=0 ; i<nums.size() ; i++){
            
            int div = 0;
            for(int j=2; j*j <= nums[i] ; j++){
                if(nums[i] % j == 0 && div == 0){
                    div = j;
                }
                else if(nums[i] % j == 0 && div != 0){
                    div = 0;
                    break;
                }
            }
            if(div != 0 && nums[i]/div != div){
                sum += 1 + div + nums[i]/div + nums[i];
            }
        }
       
        return sum;
    }
};