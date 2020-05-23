#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    
    while(cin >> n){
        long long res = INT64_MIN;
        vector<vector<long long>> matrix(n+1, vector<long long>(n+1));
        vector<vector<long long>> colSum(n+1, vector<long long>(n+1));
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n ;j++){
                cin >> matrix[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n ;j++){
                colSum[i][j] = colSum[i - 1][j] + matrix[i][j];
            }
        }
        for (int i = 1; i <= n; i++){
            for (int j = i; j<=n ;j++){
                vector<long long> nums(n+1);
                for (int k = 1; k <= n; k++){
                    nums[k] = colSum[j][k] - colSum[i - 1][k];
                    nums[k] = max(nums[k], nums[k - 1] + nums[k]);
                    res = max(res, nums[k]);
                }
            }
        }
        cout << res << endl;
    }
    
}