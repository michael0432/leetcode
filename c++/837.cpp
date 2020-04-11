class Solution {
public:
    double new21Game(int N, int K, int W) {
        vector<int> dp(N + 1, 0);
        dp[0] = 1;
        double sum = 1;
        if(K == 0)
            return 1;
        for (int i = 1; i < dp.size();i++){
            dp[i] = sum / W;
            if(i < K)
                sum += dp[i];
            if(i-W >= 0 && i-W < K)
                sum -= dp[i - W];
        }
        
    }
};  