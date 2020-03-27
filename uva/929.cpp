#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <unordered_map>

using namespace std;

class Node{
public:
    int r;
    int c;
    int cost;
    int distance;
    //int predecessor;
    //vector<pair<int, int> > l;
    Node(int row, int col, int ct){
        distance = INT_MAX-1000;
        //predecessor = -1;
        r = row;
        c = col;
        cost = ct;
    };
    Node(){

    };
};

class Compare{
public:
    bool operator() (const Node& n1, const Node& n2){
        return n1.distance > n2.distance;
    }
};


int getNodeId(int i, int j, int c_num){
    return i * c_num + j;
}

void relax(Node n, vector<vector<Node>>& all_node, priority_queue<Node, vector<Node>, Compare>& pq){
    int source_dis = n.distance;
    if(n.r-1 >= 0){
        int idxr = n.r-1, idxc = n.c;
        if(all_node[idxr][idxc].distance > source_dis+all_node[idxr][idxc].cost){
            all_node[idxr][idxc].distance = source_dis+all_node[idxr][idxc].cost;
            //all_node[idxr][idxc].predecessor = source;
            pq.push(all_node[idxr][idxc]);
        }
    }
    if(n.r+1 < all_node.size()){
        int idxr = n.r+1, idxc = n.c;
        if(all_node[idxr][idxc].distance > source_dis+all_node[idxr][idxc].cost){
            all_node[idxr][idxc].distance = source_dis+all_node[idxr][idxc].cost;
            //all_node[idxr][idxc].predecessor = source;
            pq.push(all_node[idxr][idxc]);
        }
    }
    if(n.c-1 >= 0){
        int idxr = n.r, idxc = n.c-1;
        if(all_node[idxr][idxc].distance > source_dis+all_node[idxr][idxc].cost){
            all_node[idxr][idxc].distance = source_dis+all_node[idxr][idxc].cost;
            //all_node[idxr][idxc].predecessor = source;
            pq.push(all_node[idxr][idxc]);
        }
    }
    if(n.c+1 < all_node[0].size()){
        int idxr = n.r, idxc = n.c+1;
        if(all_node[idxr][idxc].distance > source_dis+all_node[idxr][idxc].cost){
            all_node[idxr][idxc].distance = source_dis+all_node[idxr][idxc].cost;
            //all_node[idxr][idxc].predecessor = source;
            pq.push(all_node[idxr][idxc]);
        }
    }
    return;
}

int DIJ(vector<vector<int>>& v){
    
    vector<vector<Node>> all_node(v.size(),vector<Node>(v[0].size()));
    vector<vector<bool>> visit_mem(v.size(),vector<bool>(v[0].size(), false));
    int v_num = v.size() * v[0].size();
    priority_queue<Node, vector<Node>, Compare> pq;
    for(int i=0 ; i<v.size() ; i++){
        for(int j=0 ; j<v[i].size() ; j++){
            Node n(i,j,v[i][j]);
            all_node[i][j] = n;
        }
    }
    all_node[0][0].distance = v[0][0];

    pq.push(all_node[0][0]);
    for(int i=0 ; i<v_num ; i++){
        while(!pq.empty()){
            Node target = pq.top();
            pq.pop();
            if(!visit_mem[target.r][target.c]){
                visit_mem[target.r][target.c] = true;
                relax(target, all_node, pq);
            }
            else{
                break;
            }
        }
    }
    return all_node[all_node.size()-1][all_node[0].size()-1].distance;
}

int main(){
    int mazeNum;
    cin >> mazeNum;
    for(int i=0 ; i<mazeNum ; i++){
        int r, c;
        cin >> r >> c;
        vector<vector<int> > v(r,vector<int>(c,0));
        for(int j=0 ; j<r ; j++){
            for(int k=0 ; k<c ; k++){
                cin >> v[j][k];
            }
        }
        cout << DIJ(v) << endl;
    }
}