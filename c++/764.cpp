class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        unordered_set<int> m;
        vector<vector<int>> dp(N, vector<int>(N));
        int output = 0;

        for (int i = 0; i < mines.size(); i++){
            m.insert(mines[i][0] * N + mines[i][1]);
        }

        for (int j = 0; j < N; j++){
            int cnt = 0;
            // up
            for (int i = 0; i < N; i++){
                if(m.count(i*N + j) == 0)
                    cnt++;
                else
                    cnt = 0;
                dp[i][j] = cnt;
            }
            cnt = 0;
            // down
            for (int i = N-1; i >= 0; i--){
                if(m.count(i*N + j) == 0)
                    cnt++;
                else
                    cnt = 0;
                dp[i][j] = min(dp[i][j], cnt);
            }
        }
        for (int i = 0; i < N; i++){
            int cnt = 0;
            // left
            for (int j = 0; j < N; j++){
                if(m.count(i*N + j) == 0)
                    cnt++;
                else
                    cnt = 0;
                dp[i][j] = min(dp[i][j], cnt);
            }
            // right
            cnt = 0;
            for (int j = N-1; j >= 0; j--){
                if(m.count(i*N + j) == 0)
                    cnt++;
                else
                    cnt = 0;
                dp[i][j] = min(dp[i][j], cnt);
                output = max(output, dp[i][j]);
            }
        }
        return output;
    }
};