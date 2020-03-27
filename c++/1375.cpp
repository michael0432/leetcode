class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        int ridx = -1, cnt = 0;
        for(int i=0 ; i<light.size() ; i++){
            ridx = max(light[i], ridx);
            if(i+1 == ridx) cnt++;
        }
        return cnt;
    }
};