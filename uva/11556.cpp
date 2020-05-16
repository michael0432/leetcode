#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstdio>
#include <cmath>

using namespace std;

double solve(vector<vector<double>>& dp, vector<double>& prices, vector<double>& favors, int money, int K, int N){
    double output = 0;
    for (int i = 0; i < K; i++){
        for (int j = money; j >= prices[i]; j--){
            for (int k = 1; k <= (N + 1) * 2; k++){
            // buy 1
                if(j >= prices[i] && k > 0){
                    dp[j][k] = max(dp[j][k], dp[j - prices[i]][k - 1] + favors[i]);
                }
            // buy 2
                if(j >= prices[i] * 2 && k > 1){
                    dp[j][k] = max(dp[j][k], dp[j - prices[i] * 2][k - 2] + favors[i] * 2);
                }
                //output = max(output, dp[j][k]);
            }
        }
    }
    for (int i = 0; i <= money; i++){
        for (int j = 0; j <= (N + 1) * 2; j++){
            output = max(output, dp[i][j]);
        }
    }

    return output;
}

int main(){
    int N, x, T, K;
    while(cin >> N >> x >> T >> K && N+x+T+K != 0){
        int money = floor(double(x * (N + 1)) / 1.1 - T * (N+1));
        //cout << money << endl;
        vector<double> prices(K);
        vector<double> favors(K);
        for (int i = 0; i < K; i++){
            cin >> prices[i];
            double tmp;
            for (int j = 0; j < N + 1; j++){
                cin >> tmp;
                favors[i] += tmp;
            }
        }
        vector<vector<double>> dp(money + 1, vector<double>((N + 1) * 2 + 1));
        printf("%.2lf\n", solve(dp, prices, favors, money, K, N) / (N + 1));
    }
}