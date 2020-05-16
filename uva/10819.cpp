#include <iostream>
#include <vector>

using namespace std;


int main(){
    int m, n;
    while(cin >> m >> n){
        if(m > 1800)
            m += 200;
        vector<int> prices(n);
        vector<int> favor(n);
        vector<int> dp(m+1);
        for (int i = 0; i < n; i++){
            cin >> prices[i] >> favor[i];
        }
        for (int i = 0; i < n; i++){
            for (int j = m; j >= prices[i]; j--){
                //cout << 
                if(j == prices[i] || dp[j - prices[i]] > 0)
                    dp[j] = max(dp[j], dp[j - prices[i]] + favor[i]);
            }
        }

        int out = -1;

        if(m-200 > 1800 && m-200 <= 2000){
            for (int i = 0; i < m - 200; i++){
                out = max(out, dp[i]);
                cout << i << " " <<out << endl;
            }
            for (int i = 2001; i <= m; i++){
                out = max(out, dp[i]);
                cout << i << " " << out << endl;
            }

        }
        else{
            for (int i = 0; i <= m; i++){
                out = max(out, dp[i]);
            }
        }
        cout << out;
    }
}