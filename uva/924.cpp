#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Node{
public:
    int val;
    int status;
    int dis;
    vector<int> friends;
    Node(int val){
        val = val;
        status = 0;
        dis = -1;
    }
};

void solution(vector<Node> all_node, int source){
    int max_spread = 0;
    int max_spread_day = 0;
    int now_day = 1;
    if(all_node[source].friends.size() == 0){
        cout << 0 << endl;
        return;
    }
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int size = q.size();
        int spread = 0;
        for(int i=0 ; i<size ; i++){
            int now_p_id = q.front();
            if(all_node[now_p_id].status != 2){
                all_node[now_p_id].status = 1;
                for(int j=0 ; j<all_node[now_p_id].friends.size() ; j++){
                    if(all_node[all_node[now_p_id].friends[j]].status == 0){
                        q.push(all_node[now_p_id].friends[j]);
                        //cout << all_node[now_p_id].friends[j] << endl;
                        spread ++;
                        all_node[all_node[now_p_id].friends[j]].status = 1;
                    }
                }
            }
            all_node[now_p_id].status = 2;
            q.pop();
        }

        if(spread > max_spread){
            max_spread = spread;
            max_spread_day = now_day;
        }
        now_day += 1;
    }
    cout << max_spread << " " << max_spread_day << endl;
    return;
}

int main(){
    int E;
    int T;
    cin >> E;
    vector<Node> all_node;
    for(int i=0 ; i<E ;i++){
        Node n(i);
        all_node.push_back(n);
    }
    for(int i=0 ; i<E ;i++){
        int friend_num;
        cin >> friend_num;
        for(int j=0 ; j<friend_num ; j++){
            int f;
            cin >> f;
            all_node[i].friends.push_back(f);
        }
    }
    cin >> T;
    for(int i=0 ; i<T ;i++){
        int source;
        cin >> source;
        solution(all_node, source);
    }
}