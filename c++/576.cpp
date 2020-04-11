class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<vector<long long>>> dp;
    int dfs(int m, int n, int i, int j, int N){
        int mod = 1000000007;
        if(N == -1)
            return 0;
        if(i < 0 || i >= m || j < 0 || j >= n)
            return 1;
        if(dp[i][j][N] != -1)
            return dp[i][j][N];
        
        long long sum = 0;
        for (int t = 0; t < 4; t++){
            sum += dfs(m, n, i+dir[t][0], j+dir[t][1], N-1) % mod;
        }
        dp[i][j][N] = sum % mod;
        return sum % mod;
    }

    int findPaths(int m, int n, int N, int i, int j) {
        dp.resize(m, vector<vector<long long>>(n, vector<long long>(N+1, -1)));
        return dfs(m, n, i, j, N);
    }
};