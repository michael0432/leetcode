#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxFlow(vector<vector<int>>& graph, int s_n, int d_n, int nNum){
    int output = 0;
    vector<vector<int>> flow(nNum+1, vector<int>(nNum+1, 0));

    while(1){
        //bfs
        vector<int> bottleneck(nNum + 1, 0);
        bottleneck[s_n] = INT_MAX;
        queue<int> q;
        q.push(s_n);
        
        vector<int> previousNode(nNum+1, 0);
        while(!q.empty() && bottleneck[d_n] == 0){
            int cur = q.front();
            q.pop();
            for (int i = 1; i <= nNum; i++){
                if(bottleneck[i] == 0 && graph[cur][i] > flow[cur][i]){
                    q.push(i);
                    previousNode[i] = cur;
                    bottleneck[i] = min(bottleneck[cur], graph[cur][i] - flow[cur][i]);
                }
            }
        }
        if(bottleneck[d_n] == 0)
            break;
        for (int i = d_n; i != s_n; i = previousNode[i]){
            flow[previousNode[i]][i] += bottleneck[d_n];
            flow[i][previousNode[i]] -= bottleneck[d_n];
        }

        output += bottleneck[d_n];
    }
    

    return output;
}

int main(){
    int n, s, d, e;
    int caseNum = 1;
    while(cin >> n && n!=0){
        cin >> s >> d >> e;
        vector<vector<int>> v(n+1, vector<int>(n+1,0));
        int v1, v2, b;
        for (int i = 0; i < e; i++){
            cin >> v1 >> v2 >> b;
            v[v1][v2] += b;
            v[v2][v1] += b;
        }
        cout << "Network " << caseNum << endl;
        cout << "The bandwidth is " << maxFlow(v, s, d, n) << "." << endl;
        caseNum++;
    }
    
}