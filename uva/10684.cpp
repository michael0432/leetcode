#include <vector>
#include <iostream>

using namespace std;

int main(){
    int N;
    while(cin >> N && N != 0){
        vector<int> nums(N);
        vector<int> maxv(N);
        vector<int> minv(N);
        int res = INT_MIN;
        for (int i = 0; i < N; i++){
            cin >> nums[i];
            maxv[i] = nums[i];
            minv[i] = nums[i];
            if(i != 0){
                maxv[i] = max(maxv[i], maxv[i - 1] + nums[i]);
                minv[i] = min(maxv[i], maxv[i - 1] + nums[i]);
            }
            res = max(res, maxv[i]);
        }
        if(res > 0){
            cout << "The maximum winning streak is " << res << "." << endl;
        }
        else{
            cout << "Losing streak." << endl;
        }
    }
}