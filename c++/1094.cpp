class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> caps(1001, 0);
        for (int i = 0; i < trips.size(); i++){
            caps[trips[i][1]] += trips[i][0];
            caps[trips[i][2]] -= trips[i][0];
        }
        int cnt = 0;
        for (int i = 0; j <= 1000; j++){
            cnt += caps[i];
            if(cnt > capacity)
                return false;
        }
        return true;
    }
};