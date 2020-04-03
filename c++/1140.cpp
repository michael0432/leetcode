class Solution {
public:

    int stoneGameII(vector<int>& piles) {
        int sum = 0;
        vector<int> ressum;
        vector<vector<int>> dp(piles.size(),vector<int>(piles.size(), 0));
        for (int i = 0; i < piles.size(); i++){
            sum += piles[i];
        }
        for (int i = 0; i < piles.size(); i++){
            ressum.push_back(sum);
            sum -= piles[i];
        }
        for (int i = 0; i < piles.size(); i++){
            for (int j = 0; j < piles.size(); j++){
                if(2*j >= piles.size() - i){
                    dp[i][j] = ressum[i];
                }
            }
        }

        for (int i = piles.size() - 1 ; i >= 0; i--){
            for (int j = piles.size()-1 ; j >= 0; j--){
                for (int x = 1; x <= 2 * j && i+x < piles.size(); x++){
                    dp[i][j] = max(dp[i][j], ressum[i] - dp[i + x][max(j, x)]);
                }
            }
        }
        return dp[0][1];
    }
};