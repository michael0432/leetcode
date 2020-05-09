#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

#define S 36
#define T 37
#define N 40

using namespace std;

int maxFlow(vector<vector<int>>& graph, vector<vector<int>>& flow, int s_n, int d_n){
    int output = 0;
    // residual network
    
    while(1){
        //bfs
        vector<int> bottleneck(N, 0);
        bottleneck[S] = INT_MAX;
        queue<int> q;
        q.push(S);
        
        vector<int> previousNode(N, 0);
        
        while(!q.empty() && bottleneck[T] == 0){
            int cur = q.front();
            q.pop();
            
            for (int i = 0; i < N; i++){
                if(bottleneck[i] == 0 && graph[cur][i] > flow[cur][i]){
                    q.push(i);
                    
                    previousNode[i] = cur;
                    
                    bottleneck[i] = min(bottleneck[cur], graph[cur][i] - flow[cur][i]);
                }
            }
        }
        
        if(bottleneck[T] == 0)
            break;
        
        for (int i = T; i != S; i = previousNode[i]){
            flow[previousNode[i]][i] += bottleneck[T];
            flow[i][previousNode[i]] -= bottleneck[T];
        }

        output += bottleneck[T];
        
        
    }

    return output;
}

void parse(string s, vector<vector<int>>& v, int& user_num){
    int program = s[0] - 'A';
    int num = s[1] - '0'; // char -> int '4' -> 4
    v[S][program] += num;
    // user_num : SUM OF v[S][A~Z] 
    user_num += num;
    for (int i = 3; i < s.size()-1; i++){
        int com = s[i] - '0' + 26;
        v[program][com] = 1;
    }
}


int main(){
    string s;
    
    while(getline(cin, s) && s.size() != 0){
        // 1 case
        int user_num = 0;
        vector<vector<int>> v(N, vector<int>(N,0));
        vector<vector<int>> flow(N, vector<int>(N, 0));
        for (int i = 26; i <= 35; i++){
            v[i][T] = 1;
        }
        parse(s, v, user_num);
        while(getline(cin, s) && s.size() != 0){
            parse(s, v, user_num);
        }
        // input done

        int mflow = maxFlow(v, flow,S,T);
        if(mflow != user_num){
            cout << "!" << endl;
        }
        else{
            for (int x = 26; x <= 35; x++){
                bool b = true;
                for (int v = 0; v <= 25; v++){
                    if(flow[v][x]){
                        cout << (char)(v + 'A'); // 0 -> 'A'
                        b = false;
                        break;
                    }
                }
                if(b)
                    cout << "_";
            }
            cout << endl;
        }  
    }
    
}