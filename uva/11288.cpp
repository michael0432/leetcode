#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

class edge{
public:
    int v1;
    int v2;
    double distance;   
};

class vertex{
public:
    int x;
    int y;
};

struct Compare
{
    inline bool operator() (const edge& e1, const edge& e2)
    {
        return (e1.distance < e2.distance);
    }
};

// class Compare{
// public:
//     bool operator() (const edge& e1, const edge& e2){
//         return e1.distance > e2.distance;
//     }
// };

float getdistance(int x1, int y1, int x2, int y2){
    return sqrt((x1-x2) * (x1-x2) + (y1-y2) * (y1-y2));
}

int find(int target, vector<int>& disjoint_set){
    return target == disjoint_set[target] ? target : find(disjoint_set[target], disjoint_set);
}

bool equivlence(int t1, int t2, vector<int>& disjoint_set){
    return find(t1, disjoint_set) == find(t2, disjoint_set);
}

void union_set(int x, int y, vector<int>& disjoint_set){
    disjoint_set[find(x, disjoint_set)] = find(y, disjoint_set);
}

vector<int> ans(vector<edge>& edges, int threshold, int total_v){
    double road_dis = 0;
    double rail_dis = 0;
    int state_num = 1;
    vector<int> set;

    sort(edges.begin(), edges.end(), Compare());
    //cout << edges[0].distance << " " << edges[1].distance << endl;
    for(int i=0 ; i<total_v ; i++){
        set.push_back(i);
    }

    for(int i=0 ; i<edges.size() ; i++){
        if(!equivlence(edges[i].v1, edges[i].v2, set)){
            // choose
            if(edges[i].distance > threshold){
                // rail
                rail_dis += edges[i].distance;
                state_num ++;
            }
            else{
                // road
                road_dis += edges[i].distance;
            }
            union_set(edges[i].v1, edges[i].v2, set);
        }
        else{
            // cycle, 這個邊是cylce裡最大的邊
            // ans 
            // edges[i];
        }
    }
    vector<int> output = {state_num, (int)round(road_dis), (int)round(rail_dis)};
    return output;
}

int main(){
    int T;
    cin >> T;
    for(int i=0 ; i<T ; i++){
        int n,r;
        cin >> n >> r;
        vector<vertex> vs;
        vector<edge> es;
        for(int j=0 ; j<n ; j++){
            vertex v;
            cin >> v.x >> v.y;
            vs.push_back(v);
        }
        for(int j=0 ; j<n ; j++){
            for(int k=j+1 ; k<n ; k++){
                edge e;
                e.v1 = j;
                e.v2 = k;
                e.distance = getdistance(vs[j].x,vs[j].y,vs[k].x,vs[k].y); 
                es.push_back(e);
            }
        }
        vector<int> out = ans(es, r, n);
        cout << "Case #" << i+1 << ": " << out[0] << " " << out[1] << " " << out[2]<< endl;
    }
    
}