class Compare{
public:
    bool operator() (const pair<int, int> &a, const pair<int, int> &b){
        return a.second > b.second;
    }
};

class Solution {
public:

    

    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        unordered_map<int, vector<pair<int,int>>> graph(N+1);

        for (int i = 0; i < times.size(); i++){
            graph[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> dist(N + 1, INT_MAX);
        vector<bool> visited(N + 1, false);
        priority_queue < pair<int, int>, vector<pair<int, int>>, Compare> pq;
        dist[K] = 0;
        //visited[K] = true;
        pq.push({K, 0});

        while(!pq.empty()){
            pair<int, int> tmp = pq.top();
            pq.pop();
            
            if(visited[tmp.first])
                continue;
            visited[tmp.first] = true;
            //cout << graph[tmp.first].size() << endl;
            for(int i=0 ; i<graph[tmp.first].size() ; i++){
                int new_dis = tmp.second + graph[tmp.first][i].second;
                //cout << graph[tmp.first][i].first << endl;
                if(new_dis < dist[graph[tmp.first][i].first]){
                    
                    dist[graph[tmp.first][i].first] = new_dis;
                    pq.push({graph[tmp.first][i].first, dist[graph[tmp.first][i].first]});
                }
            }
        }
        int max_time = INT_MIN;
        for (int i = 1; i < dist.size();i++){
            max_time = max(dist[i], max_time);
        }
        if(max_time == INT_MAX)
            return -1;
        else
            return max_time;
    }
};