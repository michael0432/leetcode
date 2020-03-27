class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1]-a[0] < b[1]-b[0];
        });
        for(int i=0 ; i<intervals.size() ; i++){
            for(int j=i+1 ; j<intervals.size() ; j++){
                if(intervals[i][0] >= intervals[j][0] && intervals[i][1] <= intervals[j][1]){
                    //remove
                    cnt++;
                    break;
                }
            }
        }
        return intervals.size() - cnt;
    }
};