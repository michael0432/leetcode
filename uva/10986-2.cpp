#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<climits>
using namespace std;
class edge {
public:
	int des;
	int weight;
};
class node {
public:
	int pos;
	int dis;
	vector<edge> edges;
};
class Compare {
public:
	bool operator()(const node& n1,const node& n2) {
		return n1.dis > n2.dis;
	}
};
string ans(vector<node> map, int s, int t) {
	priority_queue<node, vector<node>, Compare> q;
	q.push(map[s]);
	int n = map.size() - 1;
	vector<bool> b(map.size(),false);
	int ans = 0;
	for (int i = 0;i < n;i++) {
		while (!q.empty()) {
			node temp = q.top();
			if (b[temp.pos]) {
				q.pop();
				break;
			}
			b[temp.pos] = true;
			q.pop();
			for (int j = 0;j < temp.edges.size();j++) {
				int des_dis = map[temp.edges[j].des].dis;
				if (temp.dis + temp.edges[j].weight < des_dis) {
					map[temp.edges[j].des].dis = temp.dis + temp.edges[j].weight;
					ans = map[temp.edges[j].des].dis;
					q.push(map[temp.edges[j].des]);
				}
			}
		}
	}
	if (map[t].dis != INT_MAX) {
		return to_string(map[t].dis);
	}
	else {
		return "unreachable";
	}

}
int main() {
	int cases;
	
	
	cin >> cases;
	for (int i = 0;i < cases;i++) {
		
		int u, v, w, n, m, s, t;
		cin >> n >> m >> s >> t;
		vector<node> map(n);
		for (int j = 0;j < n;j++) {
			node n1;
			n1.pos = j;
			if (j == s) {
				n1.dis = 0;
			}
			else {
				n1.dis = INT_MAX;
			}
			map[n1.pos] = n1;
		}
		if (m == 0) {
			cout << "Case #" << i+1 << ": " << "unreachable" << endl;
		}
		else {
			for (int j = 0;j < m;j++) {
				cin >> u >> v >> w;//雙向
				edge e1;
				e1.des = v;
				e1.weight = w;
				map[u].edges.push_back(e1);
				edge e2;
				e2.des = u;
				e2.weight = w;
				map[v].edges.push_back(e2);
			}
			cout << "Case #"<<i+1<<": "<<ans(map, s, t) << endl;
		}
	}
}