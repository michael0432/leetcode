#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp = grid;
        for(int i=1 ; i<dp.size() ; i++){
            dp[i][0] += dp[i-1][0];
        }
        for(int j=1 ; j<dp[0].size() ; j++){
            dp[0][j] += dp[0][j-1];
        }
        for(int i=1 ; i<dp.size() ; i++){
            for(int j=1 ; j<dp[i].size() ; j++){
                dp[i][j] += min(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[dp.size()-1][dp[0].size()-1];
    }
};

int main(){
    vector<vector<int>> grid = {{1,3,1},{1,5,1},{4,2,1}};
    Solution s;
    cout << s.minPathSum(grid) << endl;
}