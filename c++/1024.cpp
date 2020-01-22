#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        if(T == 0) return 0;
        int now_end = 0;
        int clip_num = 1;
        for(int i=0 ; i<clips.size() ; i++){
            if(clips[i][0] == 0){
                now_end = max(now_end,clips[i][1]);
            }
        }
        if(now_end == 0) return -1;
        while(now_end < T){
            int tmp = 0;
            for(int i=0 ; i<clips.size() ; i++){
                if(clips[i][0] <= now_end){
                    tmp = max(tmp,clips[i][1]);
                }
            }
            if(tmp <= now_end) return -1;
            else now_end = tmp;
            clip_num += 1;
        }
        return clip_num;
    }
};