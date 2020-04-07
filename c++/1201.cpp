class Solution {
public:
    int nthUglyNumber(int n, int a, int b, int c) {
        vector<int> v = {a, b, c};
        sort(v.begin(), v.end());
        vector<int> dp = v;
        int idx1 = 0 , idx2 = 0, idx3 = 0;
        while(dp.size() < n){
            int n1 = dp[idx1] * v[0];
            int n2 = dp[idx2] * v[1];
            int n3 = dp[idx3] * v[2];
            int m = min(n1, min(n2, n3));
            if(m == n1)
                idx1++;
            else if(m == n2)
                idx2++;
            else
                idx3++;
            if(m != dp[dp.size()-1])
                dp.push_back(m);
        }
        return dp[n - 1];
    }
};