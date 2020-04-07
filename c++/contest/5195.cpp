class Solution {
public:

    string longestDiverseString(int a, int b, int c) {
        //vector<int> abc = {a, b, c};
        vector<int> cnt = {0, 0, 0};
        string output;
        while(a > 0 || b > 0 || c > 0){
            vector<int> v = {a, b, c};
            sort(v.begin(), v.end(), greater<int>());
            bool flag = true;
            for (int i = 0; i <= 2; i++){
                flag = true;
                if(v[i] == a && a > 0){
                    if(cnt[0] < 2){
                        output += "a";
                        cnt[0]++;
                        cnt[1] = 0;
                        cnt[2] = 0;
                        flag = false;
                        a--;
                        break;
                    }
                }
                if(v[i] == b && b > 0){
                    if(cnt[1] < 2){
                        output += "b";
                        cnt[1]++;
                        cnt[0] = 0;
                        cnt[2] = 0;
                        flag = false;
                        b--;
                        break;
                    }
                }
                if(v[i] == c && c > 0){
                    if(cnt[2] < 2){
                        output += "c";
                        cnt[2]++;
                        cnt[0] = 0;
                        cnt[1] = 0;
                        flag = false;
                        c--;
                        break;
                    }
                }
            }
            if(flag)
                break;
        }
        return output;
    }
};