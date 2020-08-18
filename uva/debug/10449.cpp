#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
#include<queue>
#include<unordered_map>
using namespace std;
class edge {
public:
	int des;
	int weight;
};
class node {
public:
	int dis;
	int pos;
	vector<edge> edges;
};
int ans(vector<node> map,int end) {
	// 1. 走不到的點: return -1
	// 2. 走的到，可是路上有負環: return -1
	// 3. 走的到，路上沒負環: return distance
	// 4. if 3. , distance < 3 -> return -1

	// bfs (1.)
	queue<int> q;
	unordered_map<int, bool> mem; // color, 有沒有走過
	mem[0] = true; // 開頭
	q.push(0); // start
	bool flag = false; // 如果碰到end, flag = true
	while(!q.empty()){
		if(q.front() == end){
			flag = true;
			break;
		}
		// q.front().edges.des放進queue
		for (int x = 0; x < map[q.front()].edges.size(); x++){
			// color
			if(mem.count(map[q.front()].edges[x].des) == 0) 
				q.push(map[q.front()].edges[x].des);
			mem[map[q.front()].edges[x].des] = true;
		}
		q.pop();
	}

	// 走不到
	if(flag == false)
		return -1;
	// 1. end
	
	// 2.,3.,4.
	int d = map.size() - 1;
	
	for (int i = 0;i < d;i++) {
		for (int j = 0;j < map.size();j++) {
			for (int k = 0;k < map[j].edges.size();k++) {
				int des_dis = map[map[j].edges[k].des].dis;//RE
				
				if ((map[j].dis + map[j].edges[k].weight) < des_dis) {
					
					map[map[j].edges[k].des].dis = map[j].dis + map[j].edges[k].weight;
				}
			}
		}
	}
	//cout << map[end].dis << endl;
	for (int j = 0;j < map.size();j++) {
		for (int k = 0;k < map[j].edges.size();k++) {
			int des_dis = map[map[j].edges[k].des].dis;//RE
			if ((map[j].dis + map[j].edges[k].weight) < des_dis) {
				// negative cycle
				// bfs: 看map[j]點走的到哪些點，這些點都是負環上的點
				queue<int> q;
				unordered_map<int, bool> mem;
				mem[j] = true;
				q.push(j);
				while(!q.empty()){
					// end在負環上(j走的到end), 2.
					if(q.front() == end){
						return -1;
					}
						
					for (int x = 0; x < map[q.front()].edges.size(); x++){
						if(mem.count(map[q.front()].edges[x].des) == 0) q.push(map[q.front()].edges[x].des);
						mem[map[q.front()].edges[x].des] = true;
					}
					q.pop();
				}
				// 4.
				if (map[end].dis < 3) {
					return -1;
				}
			}
		}
	}

	
	for (int i = 0;i < map.size();i++) {
		//cout << "map[i].dis: "<< map[i].dis << endl;
	}
	
	if(map[end].dis == 100000)
		return -1;
	//3.
	return map[end].dis;
}
int main() {
	int s = 1;
	// #### input 
	int n;
	// cin.eof()
	while (cin >> n) {
		//int n;
		//cout << "n: "<< n << endl;
		/////case
		vector<int> v(n);
		for (int i = 0;i<n;i++) {
			int busy;
			cin >> busy;
			v[i] = busy;
		}
	
		int road;
		cin >> road;
		//// #### node
		vector<node> map(n);
		for(int i=0 ; i < n ; i++){
			node n;
			n.pos = i;
			if(i == 0)
				n.dis = 0;
			else
				n.dis = 100000;
			map[i] = n;
		}

		// edge
		for (int i = 0;i < road;i++) {
			int n1, n2;

			cin >> n1 >> n2;
			//cout << "n1: " << n1 << "n2: " << n2 << endl;
		
			/*node n3;
			n3.pos = n1 - 1;*/
			// map[n1 - 1].pos = n1 - 1;
			// if (map[n1 - 1].pos == 0) {
			// 	map[n1 - 1].dis = 0;
			// }
			// else {
			// 	map[n1 - 1].dis = 1000000;
			// }
			//map[n3.pos] = n3;
			edge e;
			e.des = n2-1;
			//if ((v[n1 - 1] - v[n2 - 1]) < 0) {
			e.weight = pow((v[n2-1]-v[n1-1]),3.0);
			//}
			//// ####
			// else {
			// 	e.weight = 0;
			// }
			//cout << "e.weight: "<<e.weight << endl;
			map[n1 - 1].edges.push_back(e);
			//n3.edges.push_back(e);
		
		}
		//debug
		/*for (int i = 0;i < map.size();i++) {
			for (int j = 0;j < map[i].edges.size();j++) {
				cout << "map[" << i << "].vector<edge> edges[" << j << "].des: " << map[i].edges[j].des << endl;
			}

		}*/
	
		cout << "Set #" << s << endl;
		s++;
		int q;
		cin >> q;
		
		for (int i = 0;i < q;i++) {
			int end;
			cin >> end;
			
			end--;
			
			int ans1 = ans(map, end);
			if (ans1 < 3) {
				//cout << ans1 << endl;
				cout << "?";
			}
			else {
				cout << ans1;
			}
			if(i != q-1)
				cout << endl;
		}
	}
	
	
}