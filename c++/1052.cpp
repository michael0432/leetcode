#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int originSatisfy = 0;
        int extendSatisfy = 0;
        vector<int> sat_vec;
        for (int i = 0; i < customers.size(); i++){
            if(!grumpy[i]){
                originSatisfy += customers[i];
                sat_vec.push_back(customers[i]);
            }
            else
                sat_vec.push_back(0);
        }
        
        for (int i = 0; i < customers.size() - X + 1; i++)
        {
            int extend = 0;
            for (int j = 0; j < X; j++)
            {
                extend += (customers[i + j] - sat_vec[i + j]);
            }
            extendSatisfy = max(extendSatisfy, extend);
        }
        return originSatisfy + extendSatisfy;
    }
};