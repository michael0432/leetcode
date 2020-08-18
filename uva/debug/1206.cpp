#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<sstream>
#include<cmath>
#include<algorithm>
using namespace std;
class node {
public:
	double x;
	double y;
	double dis;
};
double dist(node a,node b){
	return sqrt((a.x-b.x)* (a.x - b.x)+ (a.y - b.y)* (a.y - b.y));
}
double cross(node o,node a,node b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x-o.x);
}
bool cor_compare(const node a,const node b) {//找出左下的點
	if (a.y == b.y) {
		return a.x < b.x;
	}
	return a.y < b.y;
}
node N;//origin
bool angle_compare(node a,node b) {//照斜率及遠近排
	//cout << N.x << N.y << endl;
	double c = cross(N, a, b);
	if (c == 0) {
		return a.dis < b.dis;
	}
	else {
		return c > 0;
	}
}

void ans(vector<node> map) {
	for (int i = 0;i < map.size();i++) {
		//cout << "map[" << i << "]: " << map[i].x << " " << map[i].y << endl;
	}
	vector<node> s;
	
	sort(map.begin(),map.end(),cor_compare); // nlogn
	N = map[0];
	for (int i = 0;i < map.size();i++) { 
		map[i].dis = dist(N,map[i]);
	}
	sort(map.begin()+1, map.end(), angle_compare); // nlogn

	for (int i = 0;i < map.size();i++) { // n
		while (s.size()>=2 && cross(s[s.size()-2],s[s.size()-1],map[i])<=0) {
			s.pop_back();
		}
		s.push_back(map[i]);
	}
	s.push_back(s[0]);
	for (int i = 0;i < s.size();i++) {
		printf("(%.3lf,%.3lf)", s[i].x, s[i].y);
		//cout << "(" << s[i].x << "," << s[i].y << ")";
		if (i != s.size() - 1) {
			cout << " ";
		}
	}
	cout << endl;
}
int main() {
	string input;
	//while(1){
	while (getline(cin, input)) {
		//string input;
		char ch;
		double px,py;
		vector<node> map;
		//getline(cin, input);
		stringstream sin(input);
		input += ' ';
		while (sin>>ch>>px>>ch>>py>>ch) {
			if (ch == input[input.size() - 1]) {
				break;
			}
			node n;
			n.x = px;
			n.y = py;
			map.push_back(n);
		}
		ans(map);
	}
	
}