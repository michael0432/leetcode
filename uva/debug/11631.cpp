#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class edge {
public:
	int des;
	int start;
	int weight;
	int color;
};
struct Compare {
	inline bool operator()(const edge& e1, const edge& e2) {
		return (e1.weight < e2.weight);
	}
};
int find(int target,vector<int>& set) {
	return target == set[target] ? target : (set[target] = find(set[target], set));
}
bool equal(int n1,int n2,vector<int>& set) {
	return find(n1,set)==find(n2,set);
}
void union_set(int n1,int n2,vector<int>& set) {
	
	set[find(n1, set)] = find(n2, set);
}
int MST(vector<edge>& map,int m) {
	
	
	vector<int> set(m);
	int ans = 0;
	for (int i = 0;i < m;i++) {
		set[i] = i;
	}
	
	for (int i = 0;i < map.size();i++) {
		if (equal(map[i].start, map[i].des, set)) {
			//map[i].color = 1;
			ans += map[i].weight;
		}
		else {
			union_set(map[i].start,map[i].des,set);
			
			map[i].color = 1;
			//cout << "gggg" << endl;
		}
		
	}

	// for (int i = 0;i < m;i++) {
	// 	cout << set[i] << endl;
	// }
	
	// for (int i = 0;i < map.size();i++) {//
	// 	if (map[i].color == 0) {
			
	// 		ans += map[i].weight;
	// 	}
	// }

	return ans;
}
int main() {
	int m, n, x, y, z;
	cin >> m >> n;
	while ((m != 0) && (n != 0)) {
		vector<edge> map;
		for (int i = 0;i < n;i++) {
			cin >> x >> y >> z;
			edge e;
			e.des = y;
			e.start = x;
			e.weight = z;
			e.color = 0;
			map.push_back(e);
		}
		sort(map.begin(), map.end(), Compare());
		cout << MST(map, m) << endl;
		cin >> m >> n;
	}
	
}