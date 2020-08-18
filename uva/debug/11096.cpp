#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<cmath>
using namespace std;
class node {
public:
	double x;
	double y;
	double dis;
};
node N;

double dist(node a,node b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double cross(node o,node a,node b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool cor_compare(const node a,const node b) {
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y < b.y;
}
bool angle_compare(const node a,const node b) {
	double c = cross(N, a, b);
	if (c == 0) {
		return a.dis < b.dis;
	}
	else {
		return c>0;
	}
}
void ans(vector<node> map,double len,int nail) {
	vector<node> s;
	sort(map.begin(),map.end(),cor_compare);
	N = map[0];
	for (int i = 0;i < map.size();i++) {
		map[i].dis = dist(map[0],map[i]);
	}
	sort(map.begin()+1 , map.end(), angle_compare);
	for (int i = 0;i < map.size();i++) {
		//cout <<"map["<<i<<"]"<< map[i].dis << endl;
	}
	
	for (int i = 0;i < map.size();i++) {
		while (s.size()>=2&&cross(s[s.size()-2],s[s.size()-1],map[i])<=0) {
			s.pop_back();
		}
		s.push_back(map[i]);
	}
	
	double out=0;
	for (int i = 0;i < s.size()-1;i++) {
		//cout << "i: " << i<<endl;
		//cout << "x: " << s[i].x << " ,y: " << s[i].y << endl;
		out += dist(s[i],s[i+1]);
	}
	out += dist(s[s.size() - 1], s[0]);
	//cout << s[s.size() - 1].x << s[s.size() - 1].y << endl;
	if (out >= len) {
		printf("%.5lf\n", out);
	}
	else {
		printf("%.5lf\n", len);
		//cout << setprecision(5)<< len<<endl;//轉成小數點後五位
	}
	//printf("%.5lf\n", out);
	
}
int main() {
	int cases, nail;
	double p_x, p_y;
	double len;
	cin >> cases;
	for (int i = 0;i < cases;i++) {
		// #### 
		//cout << endl;
		cin >> len >> nail;
		vector<node> map;
		for (int j = 0;j < nail;j++) {
			cin >> p_x >> p_y;
			node n;
			n.x = p_x;
			n.y = p_y;
			map.push_back(n);
		}
		
		//vector<node> out= ans(map,len,nail);
		ans(map, len, nail);
	}
}