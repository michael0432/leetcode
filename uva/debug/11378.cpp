#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<climits>
using namespace std;
class node {
public:
	double x;
	double y;
};
struct Compare {
	inline bool operator()(const node& n1, const node& n2) {
		return (n1.x < n2.x);
	}
};
double dis(node n1, node n2) {
	//double dis1 = sqrt((n1.x - n2.x) * (n1.x - n2.x) + (n1.y - n2.y) * (n1.y - n2.y));
	double dis1 = max(abs(n1.x - n2.x), abs(n1.y - n2.y));
	return dis1;
}
double ans(vector<node>& map,int sid,int eid) {
	/*for (int i = 0;i < map.size();i++) {
		cout << map[i].x << map[i].y << endl;
	}*/
	int mid = (sid + eid) / 2;
	if (eid == sid + 1) {
		// ####
		return dis(map[sid], map[eid]);
		// return max(abs(map[sid].x - map[eid].x), abs(map[sid].y - map[eid].y));
	}
	//cout <<"debug"<<endl;
	if (sid >= eid) {
		return INT_MAX;
	}
	int pi = 0;
	int pj = 0;
	//cout << "sid: " << sid << ", eid: " << eid << endl;
	double left = ans(map, sid, mid);
	//cout << "left: "<<left << endl;

	double right = ans(map, mid+1, eid);
	//cout << "right: "<<right << endl;

	double temp = min(left, right);
	//cout << "temp: "<<temp << endl;

	double mid_line = (double)(map[mid].x + map[mid + 1].x) / 2;
	//cout << "mid_line: "<<mid_line << endl;

	double small = temp;
	//cout << "small: "<<small << endl;
	//cout << "mid: " << mid << " ,sid: " << sid << " ,map[mid-1].x: " << map[mid - 1].x << " temp: " << temp << endl;
	for (int i = mid ;i >= sid &&(mid_line-map[i].x<=temp);i--) {
		//cout << "for i" << endl;
		for (int j = mid + 1;j <= eid && (map[j].x-mid_line<=temp);j++) {
			//cout << "for j" << endl;
			if (dis(map[i], map[j])<small) {
				small = min(small, dis(map[i], map[j]));
				// pi = i;
				// pj = j;
				// cout << "i: " << i << ",j: " << j << endl;
			}
			//
		}
	}
	//cout << "debug" << endl;
	//if () {

	//}
	// ####
	return small;
}
int main() {
	int cases ;
	double p_x, p_y;
	// ####
	while (cin >> cases) {
		vector<node> map;
		for (int i = 0;i < cases;i++) {
			cin >> p_x >> p_y;
			node n;
			n.x = p_x;
			n.y = p_y;
			map.push_back(n);
		}
		sort(map.begin(), map.end(), Compare());
		int sid = 0;
		int eid = map.size()-1;
		/*for (int i = 0;i < map.size();i++) {
			cout << "map[" << i << "].x: " << map[i].x << "map[" << i << "].y: " << map[i].y << endl;
		}*/
		//int a = (int)ans(map, sid, eid);
		cout << ans(map, sid, eid) << endl;
		//cin >> cases;
	}
	
}