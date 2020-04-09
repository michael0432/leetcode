
class Solution {
public:

    void bfs(vector<int>& shortest, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges, bool color){
        unordered_map<int, pair<int,int>> m;
        queue<int> q;
        int level = 0;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            for (int i = 0; i < size; i++){
                shortest[q.front()] = min(shortest[q.front()], level);
                if(color == false){
                    for (int i = 0; i < red_edges.size(); i++){
                        if(red_edges[i][0] == q.front()){
                            if(m[red_edges[i][1]].first == 0){
                                q.push(red_edges[i][1]);
                            }
                            m[red_edges[i][1]].first = 1;
                        }
                    }
                }   
                else{
                    for (int i = 0; i < blue_edges.size(); i++){
                        if(blue_edges[i][0] == q.front()){
                            //cout << blue_edges[i][1] << " " << m.count(blue_edges[i][1]) << endl;
                            if(m[blue_edges[i][1]].second == 0){
                                //cout << blue_edges[i][1] << " " << m.count(blue_edges[i][1]) << endl;
                                q.push(blue_edges[i][1]);
                            }

                            m[blue_edges[i][1]].second = 1;
                        }
                    }
                }
                q.pop();
            }
            color = !color;
            level++;
        }
    }

    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<int> shortest(n, INT_MAX);
        shortest[0] = 0;
        bfs(shortest, red_edges, blue_edges, false);
        bfs(shortest, red_edges, blue_edges, true);
        for (int i = 0; i < shortest.size(); i++)
        {
            if(shortest[i] == INT_MAX)
                shortest[i] = -1;
        }
        return shortest;
    }
};