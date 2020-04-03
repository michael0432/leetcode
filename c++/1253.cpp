class Solution {
public:
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int total_one = 0, total_two = 0;
        vector<vector<int>> ans;
        for (int i = 0; i < colsum.size(); i++){
            if(colsum[i] == 1)
                total_one++;
            if(colsum[i] == 2)
                total_two++;
        }
        if((upper-total_two) + (lower-total_two) != total_one || upper-total_two < 0 || lower-total_two < 0)
            return ans;
        ans.resize(2, vector<int>(colsum.size(),0));
        int upper_cnt = upper - total_two;
        for (int i = 0; i < colsum.size(); i++){
            if(colsum[i] == 1){
                if(upper_cnt > 0){
                    ans[0][i] = 1;
                    upper_cnt--;
                }
                else{
                    ans[1][i] = 1;
                }
            }
            if(colsum[i] == 2){
                ans[1][i] = 1;
                ans[0][i] = 1;
            }
        }
        return ans;
    }
};