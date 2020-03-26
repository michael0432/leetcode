class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int cnt = 0, now_day = 1;
        vector<int> attend(100002,0);
        sort(events.begin(), events.end(), [](const auto& a, const auto& b){
            return a[1] < b[1];
        });
        for(int i=0 ; i<events.size() ; i++){
            for(int j=events[i][0] ; j<=events[i][1] ; j++){
                if(attend[j] == 0){
                    cnt++;
                    attend[j] = 1;
                    break;
                }
            }
        }
        return cnt;
    }
};