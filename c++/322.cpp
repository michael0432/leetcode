#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(), coins.end());
        unordered_map<int, int> map;
        return count(coins, amount, map);
    }
    int count(vector<int>& coins, int amount, unordered_map<int, int>& map){
        int num = -1;
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        if(map.count(amount) != 0){
            return map[amount];
        }
        else{
            int mins = INT_MAX;
            for (int i = 0; i < coins.size(); i++){
                int cnt = count(coins, amount - coins[i], map);
                if(cnt >= 0)
                    mins = min(cnt, mins);
            }
            
            if (mins == INT_MAX || mins == -1){
                map[amount] = -1;
                return -1;
            }
            else if(mins >= 0){
                num = mins + 1;
            }
            map[amount] = num;
            //cout << amount << " " << mins << endl;
            return num;
        }
        
    }
};