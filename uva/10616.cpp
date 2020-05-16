#include <iostream>
#include <vector>

using namespace std;

int solve(vector<vector<vector<int>>>& dp, vector<int>& nums, int N, int D, int M){
    dp[0][0][0] = 1;
    for (int i = 1; i <= N; i++){
        for (int j = 0; j <= M; j++){
            for (int k = 0; k < D; k++){
                dp[i][j][k] += dp[i - 1][j][k];
                if(j != 0){
                    dp[i][j][k] += dp[i - 1][j - 1][(k - nums[i - 1] % D + D) % D];
                }
            }
        }
    }
    return dp[N][M][0];
}

int main(){
    int N, Q, D, M;
    int cnt = 1;
    while(cin >> N && cin >> Q && N!=0 && Q!=0){
        cout << "SET " << cnt << ":"<< endl;
        vector<int> nums(N);
        
        for (int i = 0; i < N;i++){
            cin >> nums[i];
        }
        
        for (int i = 0; i < Q; i++){
            cin >> D >> M;
            vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(M+1, vector<int>(D)));
            cout << "QUERY " << i+1 << ": " << solve(dp, nums, N, D, M) << endl;
        }
        cnt++;
    }
}