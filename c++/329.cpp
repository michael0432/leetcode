class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<vector<int>>& matrix, vector<vector<bool>>& visited, int r, int c){
        if(dp[r][c] != 0)
            return dp[r][c];
        if(visited[r][c])
            return 0;
        int maxi = 0;
        visited[r][c] = true;
        if(r+1 >= 0 && r+1<matrix.size() && c >=0 && c<matrix[0].size() && matrix[r+1][c] > matrix[r][c])
            maxi = max(maxi, dfs(matrix, visited, r + 1, c));
        if(r-1 >= 0 && r-1<matrix.size() && c >=0 && c<matrix[0].size() && matrix[r-1][c] > matrix[r][c])
            maxi = max(maxi, dfs(matrix, visited, r - 1, c));
        if(r >= 0 && r<matrix.size() && c+1 >=0 && c+1<matrix[0].size() && matrix[r][c+1] > matrix[r][c])
            maxi = max(maxi, dfs(matrix, visited, r, c + 1));
        if(r >= 0 && r<matrix.size() && c-1 >=0 && c-1<matrix[0].size() && matrix[r][c-1] > matrix[r][c])
            maxi = max(maxi, dfs(matrix, visited, r, c - 1));
        visited[r][c] = false;
        dp[r][c] = maxi + 1;
        return maxi + 1;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int ans = 0;
        dp.resize(matrix.size(), vector<int>(matrix[0].size(), 0));
        vector<vector<bool>> visited(matrix.size(), vector<bool>(matrix[0].size(), false));
        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                
                ans = max(ans, dfs(matrix, visited, i, j));
            }
        }
        return ans;
    }
};