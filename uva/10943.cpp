#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int N, K;
    int mod = 1000000;
    vector<vector<long long>> dp(201, vector<long long>(201));
    dp[0][0] = 1;
    for (int i = 1; i <= 200; i++){
        dp[i][0] = 1;
        for (int j = 1; j <= i; j++){
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod ;
        }
    }
    while(cin >> N && cin >> K){
        if(N == 0 && K == 0) break;
        cout << dp[N+K-1][K-1] << endl;
    }
}