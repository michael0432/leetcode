#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cases, len, n;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        int output = 0;
        cin >> len;
        vector<int> dp(len * 2, 1);
        vector<int> v;
        for (int j = 0; j < len; j++){
            cin >> n;
            v.push_back(n);
            v.insert(v.begin(), n);
        }
        for (int j = 1; j < v.size(); j++){
            for (int k = j - 1; k >= 0; k--){
                if(v[j] > v[k])
                    dp[j] = max(dp[j], dp[k] + 1);
                output = max(output, dp[j]);
            }
        }
        cout << output << endl;
    }
}