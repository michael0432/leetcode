class Solution {
public:

    bool dfs(unordered_map<int, vector<int>>& dis, vector<int>& color, int nowp, int c){
        color[nowp] = c;
        for (int i = 0; i < dis[nowp].size(); i++){
            if(color[dis[nowp][i]] == c)
                return false;
            else if(color[dis[nowp][i]] == 0){
                bool b = dfs(dis, color, dis[nowp][i], -c);
                if(!b)
                    return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> dis;
        for (int i = 0; i < dislikes.size(); i++){
            dis[dislikes[i][0]].push_back(dislikes[i][1]);
            dis[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        vector<int> color(N + 1, 0);
        for (int i = 1; i <= N;i++){
            if(color[i] == 0){
                bool b = dfs(dis, color, i, 1);
                if(!b)
                    return false;
            }
        }
        return true;
    }
};