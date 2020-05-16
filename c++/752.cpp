class Solution {
public:

    int openLock(vector<string>& deadends, string target) {
        unordered_map<string, int> dead;
        queue<string> q;
        for (int i = 0; i < deadends.size(); i++){
            dead[deadends[i]] = 1;
        }
        q.push("0000");
        int output = 0;
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                //cout << q.front() << " " << output <<endl;
                if(q.front() == target){
                    return output;
                }
                string s = q.front();
                if(dead.count(s) != 0){
                    q.pop();
                    continue;
                }
                dead[s]++;
                for (int i = 0; i < 4; i++){
                    int tmp1, tmp2, tmp3 = s[i] - '0';
                    tmp1 = ((s[i] - '0') + 1) % 10;
                    if(s[i] - '0' != 0)
                        tmp2 = ((s[i] - '0') - 1);
                    else
                        tmp2 = 9;
                    s[i] = tmp1 + '0';
                    if(dead.count(s) == 0) q.push(s);
                    s[i] = tmp2 + '0';
                    if(dead.count(s) == 0) q.push(s);
                    s[i] = tmp3 + '0';
                }
                q.pop();
            }
            output++;
        }
        return -1;
    }
};