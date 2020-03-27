#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Edge{
public:
    int des;
    int weight;
};

class Node{
public:
    int id;
    int distance;
    vector<Edge> edges;
};

bool BF(vector<Node>& ns){
    for (int i = 0; i < ns.size() - 1; i++){
        for (int j = 0; j < ns.size(); j++){
            for (int k = 0; k < ns[j].edges.size(); k++){
                ns[j].distance = min(ns[ns[j].edges[k].des].distance + ns[j].edges[k].weight, ns[j].distance);
            }
        } 
    }
    //cout << ns[0].distance << ns[1].distance << ns[2].distance << endl;
    for (int j = 0; j < ns.size(); j++){
        for (int k = 0; k < ns[j].edges.size(); k++){
            if(ns[ns[j].edges[k].des].distance + ns[j].edges[k].weight < ns[j].distance){
                return true;
            }
        }
    }
    return false;
}

int main(){
    int casen;
    cin >> casen;
    for (int i = 0; i < casen; i++){
        int n, m;
        cin >> n >> m;
        vector<Node> ns;
        for (int j = 0; j < n; j++){
            Node n;
            n.id = j;
            n.distance = INT_MAX-10000;
            ns.push_back(n);
        }
        ns[0].distance = 0;
        for (int j = 0; j < m; j++){
            int start, end, weight;
            cin >> start >> end >> weight;
            Edge e;
            e.des = end;
            e.weight = weight;
            ns[start].edges.push_back(e);
        }
        if(BF(ns))
            cout << "possible" << endl;
        else
            cout << "not possible" << endl;
    }
    

}