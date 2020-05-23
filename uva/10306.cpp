#include <vector>
#include <iostream>

using namespace std;

class Coin{
public:
    int x;
    int y;
    Coin(int x, int y){
        this->x = x;
        this->y = y;
    }
};



int main(){
    int cases, n, s;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        cin >> n >> s;
        vector<Coin> all_c;
        for (int j = 0; j < n; j++){
            int x, y;
            cin >> x >> y;
            Coin c(x, y);
            all_c.push_back(c);
        }
        vector<vector<int>> dp(s + 1, vector<int>(s + 1));
        dp[0][0] = 1;
        int res = INT_MAX;
        for (int a = 0; a < n; a++){
            for (int x = 0; x <= s; x++){
                for (int y = 0; y <= s; y++){
                    if(dp[x][y]){
                        int evx = x + all_c[a].x;
                        int evy = y + all_c[a].y;
                        if(evx > s || evy > s)
                            break;
                        if(dp[evx][evy] == 0 || dp[x][y] + 1 < dp[evx][evy]){
                            dp[evx][evy] = dp[x][y] + 1;
                        }
                        if(evx * evx + evy * evy == s * s){
                            res = min(res, dp[evx][evy]);
                        }
                    }
                }
            }
        }
        if(res == INT_MAX)
            cout << "not possible" << endl;
        else
            cout << res-1 << endl;
    }
}