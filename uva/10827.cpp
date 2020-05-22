#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cases, n;
    cin >> cases;
    for(int i=0 ; i<cases ; i++){
        cin >> n;
        int res = INT_MIN;
        vector<vector<int>> matrix(n*2+1 , vector<int>(n*2+1));
        vector<vector<int>> colSum(n*2+1 , vector<int>(n*2+1));
        for(int i=1 ; i<=n ; i++){
            for(int j=1; j<=n; j++){
                cin >> matrix[i][j];
                matrix[i+n][j] = matrix[i][j];
                matrix[i][j+n] = matrix[i][j];
                matrix[i+n][j+n] = matrix[i][j];
            }
        }
        for(int i=1 ; i<=n*2 ; i++){
            for(int j=1 ; j<=n*2 ; j++){
                colSum[i][j] = colSum[i-1][j] + matrix[i][j];
            }
        }
        for(int i=1 ; i<=n*2 ; i++){
            for(int j=i ; j<=n*2 && j-i+1<=n ; j++){
                
                for(int s=1; s<=n; s++){
                    vector<int> v(2*n+1);
                    for(int k=s; k<s+n; k++){
                        v[k] = colSum[j][k] - colSum[i-1][k];
                        v[k] = max(v[k], v[k-1] + v[k]);
                        // if(v[k-1].second < n && v[k-1].first + v[k].first > v[k].first){
                        //     v[k] = {v[k-1].first + v[k].first, v[k-1].second+1};
                        // }
                        
                        res = max(res, v[k]);
                    }
                }
                
            }
        }
        cout << res << endl;
    }
}