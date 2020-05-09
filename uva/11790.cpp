#include <iostream>
#include <vector>

using namespace std;

int main(){
    int cases, buildings;
    cin >> cases;
    for (int i = 0; i < cases; i++){
        cin >> buildings;
        vector<int> h(buildings);
        vector<int> w(buildings);
        vector<int> up(buildings);
        vector<int> down(buildings);
        for (int j = 0; j < buildings; j++){
            cin >> h[j];
        }
        for (int j = 0; j < buildings; j++){
            cin >> w[j];
        }

        int increase = 0, decrease = 0;

        for (int j = 0; j < buildings; j++){
            up[j] = w[j];
            down[j] = w[j];
            for (int k = 0; k < j; k++){
                if(h[k] < h[j] && up[j] < up[k] + w[j]){
                    up[j] = up[k] + w[j];
                }
                if(h[k] > h[j] && down[j] < down[k] + w[j]){
                    down[j] = down[k] + w[j];
                }
            }
            increase = max(increase, up[j]);
            decrease = max(decrease, down[j]);
        }
        //Case 1. Increasing (85). Decreasing (50)
        if(increase >= decrease)
            cout << "Case " << i+1 << ". " << "Increasing (" << increase << "). Decreasing (" << decrease << ")." << endl;
        else
            cout << "Case " << i+1 << ". " << "Decreasing (" << decrease << "). Increasing (" << increase << ")." << endl;
    }
}