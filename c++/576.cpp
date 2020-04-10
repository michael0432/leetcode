class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<vector<int>>> dp;
    int dfs(int m, int n, int i, int j, int N){
        if(N == -1)
            return 0;
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        if(dp[i][j][N] != -1)
            return dp[i][j][N];
        
        int sum = 0;
        for (int t = 0; t < 4; t++){
            sum += dfs(m, n, i+dir[t][0], j+dir[t][1], N-1);
        }
        dp[i][j][N] = sum;
        return sum;
    }

    int findPaths(int m, int n, int N, int i, int j) {
        dp.resize(m, vector<vector<int>>(n, vector<int>(N+1, -1)));
        return dfs(m, n, i, j, N);
    }
};