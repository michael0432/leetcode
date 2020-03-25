class Solution {
public:

    void getDigit(int i, vector<int>& ans, int low, int high){
        int start_num = 0;
        int add_num = 0;
        int x = i, y = 1;
        for( ; x >= 1 ; x-- , y++){
            start_num += y * pow(10,x-1);
            add_num += pow(10,x-1);
        }
        while(start_num < pow(10,i)){
            if(start_num >= low && start_num <= high) ans.push_back(start_num);
            if(start_num % 10 == 9){
                break;
            }
            start_num += add_num;
        }
    }

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;
        for(int i=2 ; i<=9 ; i++){
            getDigit(i, ans, low, high);
        }
        return ans;
    }
};