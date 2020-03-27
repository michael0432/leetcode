#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int station = -1;
        // int gsum = 0;
        // int csum = 0;
        // vector<int> gas_sum;
        // vector<int> cost_sum;
        // for(int i=0 ; i<gas.size() ; i++){
        //     gsum += gas[i];
        //     csum += cost[i];
        //     gas_sum.push_back(gsum);
        //     cost_sum.push_back(csum);
        // }
        
        for(int i=0 ; i<gas.size() ; i++){
            int total_gas = 0;
            if(gas[i] < cost[i]) continue;
            else{
                for(int j=0 ; j<=gas.size() ; j++){
                    int idx = (i+j) % gas.size();
                    if(j != 0){
                        if(idx == 0) total_gas -= cost[gas.size()-1];
                        else total_gas -= cost[idx-1];
                    }
                    if(total_gas < 0) break;
                    total_gas += gas[idx];
                }
            }
            cout << i << " " << total_gas << endl;
            if(total_gas >= 0){
                station = i;
                return station;
            }
        }
        return station;
    }
};