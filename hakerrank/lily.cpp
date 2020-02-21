#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

int cntSwap(vector<int> arr, vector<int> sorted){
    int cnt = 0;
    unordered_map<int, int> pos;
    for(int i=0 ; i<arr.size() ; i++){
        pos[arr[i]] = i;
    }
    for(int i=0 ; i<arr.size() ; i++){
        if(sorted[i] != arr[i]){
            int idx = pos[sorted[i]];
            pos[arr[i]] = pos[sorted[i]];
            int tmp = arr[i];
            arr[i] = sorted[i];
            arr[idx] = tmp;
            cnt += 1;
        }
    }
    //cout << cnt << endl;
    return cnt;
}

int lilysHomework(vector<int> arr) {
    
    vector<int> v1 = arr;
    vector<int> v2 = arr;
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end(), greater<int>());
    
    return min(cntSwap(arr, v1),cntSwap(arr, v2));
}



int main(){
    int n;
    vector<int> v;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    cout << lilysHomework(v);
}