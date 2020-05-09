#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, k, m;

    vector<vector<vector<long long>>> dp(51, vector<vector<long long>>(51, vector<long long>(51, 0)));
    for (int i = 0; i <= 50; i++)
        dp[0][0][i] = 1;
    for (int i = 1; i <= 50; i++){
        for (int j = 1; j <= 50; j++){
            for (int k = 1; k <= 50 ; k++){
                if(k > i){
                    dp[i][j][k] = dp[i][j][i];
                }
                else{
                    for (int x = 1; x <= i && x<=k; x++){
                        dp[i][j][k] += dp[i - x][j - 1][k];
                    } 
                }
                   
            }
        }
    }

    while (cin >> n >> k >> m){
        cout << dp[n][k][m] << endl;
    }
}