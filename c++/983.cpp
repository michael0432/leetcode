class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(366, -1);
        unordered_set<int> day;
        for (int i = 0; i < days.size(); i++){
            day.insert(days[i]);
        }
        dp[0] = 0;

        for (int i = 1; i <= 365; i++){
            if(day.count(i) == 0){
                dp[i] = dp[i - 1];
            }
            else{
                dp[i] = costs[0] + dp[i - 1];
                dp[i] = min(dp[i], costs[1] + dp[max(i - 7, 0)]);
                dp[i] = min(dp[i], costs[2] + dp[max(i - 30, 0)]);
            }
        }
        return dp[365];
    }
};