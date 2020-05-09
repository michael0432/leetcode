#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main(){
    int cases, miles;
    cin >> cases;
    for (int c = 0; c < cases; c++){
        cin >> miles;
        int m = miles / 100;
        vector<vector<int>> wind(10, vector<int>(m));
        vector<vector<int>> dp(10, vector<int>(m+1, 1000000000));
        for (int i = 9; i >= 0; i--){
            for (int j = 0; j < m; j++){
                cin >> wind[i][j];
            } 
        }

        dp[0][0] = 0;

        for (int j = 1; j <= m; j++){
            for (int i = 0; i < 10; i++){
                if(i > 0){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + 60 - wind[i - 1][j - 1]);
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + 30 - wind[i][j - 1]);
                }
                if(i < 9){
                    dp[i][j] = min(dp[i][j], dp[i+1][j - 1] + 20 - wind[i+1][j - 1]);
                }
            }
        }
        cout << dp[0][m] << endl << endl;
    }

}