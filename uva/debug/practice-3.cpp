#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

class Point {
public:
	int x;
	int y;
	int dis;
};

Point fP;

int dist(Point a, Point b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int cross(Point o, Point a, Point b) {
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}

bool cor_compare(const Point a, const Point b) {
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

bool angle_compare(const Point a, const Point b) {
	double c = cross(fP, a, b);
	if (c == 0)
		return a.dis < b.dis;
	else
		return c > 0;
}

vector<Point> graham(vector<Point> v) {
	vector<Point> st;
	sort(v.begin(), v.end() - 1, cor_compare);
	fP = v[0];
	for (int i = 1; i < v.size(); i++) {
		v[i].dis = dist(v[0], v[i]);
	}
	sort(v.begin() + 1, v.end() - 1, angle_compare);
	v[v.size() - 1] = v[0];
	//st.push_back(v[0]);
	for (int i = 0; i < v.size() - 1; i++) {
		while (st.size() >= 2 && cross(st[st.size() - 2], st[st.size() - 1], v[i]) <= 0) {
			st.pop_back();
		}
		st.push_back(v[i]);
	}
	st.push_back(v[v.size() - 1]);

	return st;
}


int main() {
	int n, k;
	cin >> n;
	cout << n << endl;
	for (int i = 0; i < n; i++) {
		cin >> k;
		vector<Point> v;
		for (int j = 0; j < k; j++) {
			Point p;
			cin >> p.x >> p.y;
			v.push_back(p);
		}
		int tmp;
		cin >> tmp; // -1
		vector<Point> out = graham(v);

		cout << out.size() << endl;
		for (int i = 0; i < out.size(); i++) {
			cout << out[i].x << " " << out[i].y << endl;
		}
		if (i != n - 1) cout << "-1" << endl;
	}
}