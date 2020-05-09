#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int maxFlow(vector<vector<int>>& graph, int s_n, int d_n, int nNum){
    int output = 0;
    // residual network n1->n2 : 5, n1->n2 : 3 (flow) n2->n1 : -3
    vector<vector<int>> flow(nNum+1, vector<int>(nNum+1, 0));
    // while(1)直到找不到argumenting path
    while(1){
        vector<int> bottleneck(nNum + 1, 0); // 存每個點的bottleneck，這個點目前有多少流量流進來
        bottleneck[s_n] = INT_MAX;
        queue<int> q;
        q.push(s_n);
        
        vector<int> previousNode(nNum+1, 0);　//存走過的路
        //bfs: one argumenting path
        while(!q.empty() && bottleneck[d_n] == 0){　
            // bfs走完或是走到終點（bottleneck[d_n]一開始是0，如果flow走到會變成不是0）
            // q.empty() -> bfs done
            // bottleneck[d_n] != 0 -> 走到終點
            int cur = q.front();
            q.pop();
            // 看每個node能不能走
            // if bottleneck[i] == 0表示這個點還沒被走過（bfs的判斷）
            // graph[cur][i] > flow[cur][i] 表示這個點還有流量可以用（flow還走的過去）
            for (int i = 1; i <= nNum; i++){
                if(bottleneck[i] == 0 && graph[cur][i] > flow[cur][i]){
                    q.push(i);
                    //存這個FLOW的路徑
                    previousNode[i] = cur;
                    // 這個點的bottleneck就是這個flow最多可以流多少過去
                    bottleneck[i] = min(bottleneck[cur], graph[cur][i] - flow[cur][i]);
                }
            }
        }
        // bfs end

        //走不到終點，表示沒有flow能到終點了，演算法結束
        if(bottleneck[d_n] == 0)
            break;
        //最後走到終點的bottleneck就是這個flow最多可以流多少，更新flow的graph
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
        // use 2 dim vector to save the graph info.
        // Ex. v[1][2] : node 1 -> node 2
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