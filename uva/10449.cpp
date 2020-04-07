#include<iostream>
#include<vector>
#include<climits>
#include<cmath>
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
	int d = map.size() - 1;
	for (int i = 0;i < d;i++) {
		for (int j = 0;j < map.size();j++) {
			for (int k = 0;k < map[j].edges.size();k++) {
				int des_dis = map[map[j].edges[k].des].dis;//RE
				if ((map[j].dis + map[j].edges[k].weight) < des_dis) {
					//cout << "map[" <<j<< "].dis: "<< map[j].dis << " ,map["<<j<<"].edges["<<k<<"].weight" << map[j].edges[k].weight << endl;
					//cout << "des_dis: " << des_dis << endl;
					map[map[j].edges[k].des].dis = map[j].dis + map[j].edges[k].weight;
					
				}
			}
		}
	}
	//找負環
	for (int j = 0;j < map.size();j++) {
		for (int k = 0;k < map[j].edges.size();k++) {
			int des_dis = map[map[j].edges[k].des].dis;//RE
			if ((map[j].dis + map[j].edges[k].weight) < des_dis) {
				//cout << "des_dis: "<<des_dis << endl;
				//找到負環，j在負環上
				//對j做bfs，找到所有在負環上的點，這些點都要output?
			}
		}
	}
	for (int i = 0;i < map.size();i++) {
		//cout << "map[i].dis: "<< map[i].dis << endl;
	}
	return map[end].dis;
}

void reset(vector<node>& map){
	map[0].dis = 0;
	for (int i = 1; i < map.size(); i++){
		map[i].dis = INT_MAX;
	}
}

int main() {
	int s = 1;
	while (!cin.eof()) {
		int n;
		cin >> n;
		/////case
		vector<int> v(n);
		for (int i = 0;i<n;i++) {
			int busy;
			cin >> busy;
			v[i] = busy;
		}
	
		int road;
		cin >> road;
		vector<node> map(road);
		for (int i = 0;i < road;i++) {
			int n1, n2;

			cin >> n1 >> n2;
			//cout << "n1: " << n1 << "n2: " << n2 << endl;
		
			/*node n3;
			n3.pos = n1 - 1;*/
			map[n1 - 1].pos = n1 - 1;
			if (map[n1 - 1].pos == 0) {
				map[n1 - 1].dis = 0;
			}
			else {
				map[n1 - 1].dis = INT_MAX;
			}
			//map[n3.pos] = n3;
			edge e;
			e.des = n2-1;
			//if ((v[n1 - 1] - v[n2 - 1]) < 0) {
			e.weight = pow((v[n2-1]-v[n1-1]),3.0);
			//}
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
				cout << "?"<<endl;
			}
			else {
				cout << ans1 << endl;
			}
			reset(map);
		}
	}
	
	
}