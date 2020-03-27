#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
class edge {
public:
	int des;
	int weight;
};
class node {
public:
	int pre;
	int dis;
	int pos;
	vector<edge> edges;
};
class Compare {
public:
	bool operator() (const node& n1, const node& n2) {
		return n1.dis > n2.dis;
	}
};
int ans(vector<node> map,int t,int exit) {
	priority_queue<node,vector<node>,Compare> q;
	q.push(map[exit-1]);
	vector<bool> b(map.size(), false);
	int counter = 0;
	int n = map.size() - 1;
	for (int j = 0;j < n;j++) {
		while (!q.empty()) {
			node temp = q.top();
			if (b[temp.pos - 1]) {
				q.pop();
				break;
			}
			b[temp.pos - 1] = true;
			q.pop();
			for (int i = 0;i < temp.edges.size();i++) {
				int des_dis = map[temp.edges[i].des - 1].dis;
				if (temp.dis + temp.edges[i].weight < des_dis) {
					map[temp.edges[i].des - 1].dis = temp.dis + temp.edges[i].weight;
					q.push(map[temp.edges[i].des - 1]);
				}
			}


		}
	}
	for (int i = 0;i < map.size();i++) {
		if (map[i].dis <= t) {
			counter++;
		}
	}

	return counter;
}
int main() {
	int cases, cells, exit, timer, con, a, b, c;
	cin >> cases;
	cout << endl;
	for (int i = 0;i < cases;i++) {
		cin >> cells;
		cin >> exit;
		cin >> timer;
		cin >> con;
		vector<node> map;
		for (int j = 0;j < cells;j++) {
			node n;
			if (j+1 == exit) {
				n.dis = 0;
			}
			else {
				n.dis = INT_MAX;
			}
			n.pre = -1;
			n.pos = j + 1;
			n.edges = {};

			map.push_back(n);
		}
		
		for (int j = 0;j < con;j++) {
			cin >> a >> b >> c;
			edge e;
			e.des = a;
			e.weight = c;
			map[b - 1].edges.push_back(e);
		}

		cout << ans(map,timer,exit) << endl;
		if (i!=cases-1) {
			cout << endl;
		}
		

	}
}