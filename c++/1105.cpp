class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        vector<int> dp(books.size()+1,0);
        for (int i = 1; i <= books.size(); i++){
            dp[i] = dp[i - 1] + books[i-1][1];
            int width = books[i - 1][0];
            int height = books[i - 1][1];
            for (int j = i - 1; j > 0 && width + books[j - 1][0] <= shelf_width ; j--){
                width += books[j - 1][0];
                height = max(height, books[j - 1][1]);
                dp[i] = min(dp[i], height + dp[j-1]);
            }
        }

        return dp[books.size()];
    }
};