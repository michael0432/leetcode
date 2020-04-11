class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<vector<int>> cp(difficulty.size(), vector<int>(2));
        for (int i = 0; i < difficulty.size();i++){
            cp[i][0] = difficulty[i];
            cp[i][1] = profit[i];
        }
        sort(cp.begin(), cp.end(), [](const vector<int> &a, const vector<int> &b) {
            return a[0] < b[0];
        });
        sort(worker.begin(), worker.end());
        int cp_idx = 0, total = 0, now_max = 0;
        for (int i = 0; i < worker.size(); i++){
            while(cp_idx <= difficulty.size()){
                if(cp_idx == difficulty.size() || worker[i] < cp[cp_idx][0]){
                    if(cp_idx != 0) 
                        total += now_max;
                    break;
                }
                now_max = max(now_max, cp[cp_idx][1]);
                cp_idx++;
                
            }
        }
        return total;
    }
};