#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<algorithm>
using namespace std;
class edge {
public:
	int des;
	int start;
	int weight;
};
class node {
public:
	int x;
	int y;
};
struct Compare {
	inline bool operator()(const edge& e1,const edge& e2) {
		return (e1.weight<e2.weight);
	}
};
int find(int target,vector<int>& set) {
	return target == set[target] ? target : find(set[target], set);
}
bool equal(int n1,int n2,vector<int>& set) {
	return find(n1, set) == find(n2, set);
}
void union_set(int n1,int n2,vector<int>& set) {
	set[find(n1,set)] = find(n2,set);
}
void ans(vector<edge> map,int edges, int n) {
	vector<int> set(n);
	vector<int> ans ;
	sort(map.begin(), map.end(), Compare());
	
	for (int i = 0;i < n;i++) {
		set[i] = i;
	}
	for (int i = 0;i < map.size();i++) {
		//cout << "w: "<< map[i].weight << " " <<map[i].start << " " <<map[i].des << endl;
		if (equal(map[i].start, map[i].des, set)) {
			ans.push_back(map[i].weight);
		}
		else {
			union_set(map[i].start,map[i].des,set);
		}
	}
	if (ans.size() != 0) {
		for (int i = 0;i < ans.size();i++) {
			cout << ans[i];
			if (i != ans.size() - 1) {
				cout << " ";
			}
			
		}
		cout << endl;
	}
	else {
		cout << "forest" << endl;
	}
}
int main() {
	int node, edges, u, v, w;
	
	while (cin >> node >> edges && node != 0 && edges != 0) {
		vector<edge> map(edges);
		for (int i = 0;i < edges;i++) {
			cin >> u >> v >> w;
			edge e;
			e.start = u;
			e.des = v;
			e.weight = w;
			map[i] = e;
		}
		ans(map,edges, node);
		//cin >> node >> edges;
	}
}