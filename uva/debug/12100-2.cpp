#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
class Node {
public:
	int val;
	int pos;
};
/*
class Compare {
public:
	bool operator()(const Node& n1, const Node& n2) {
		return n1.val < n2.val;
	}
};*/
//////將temp.val比大小的priority queue
int sol(vector<Node> v, int m) {
	//cout << "m: " << m << endl;
	vector<int> temp1;
	for (int i = 0;i < v.size();i++) {
		temp1.push_back(v[i].val);
	}
	sort(temp1.begin(), temp1.end());
	queue<int> temp2;//放由大到小的v.val
	
	for (int i = temp1.size()-1;i >=0;i--) {
		temp2.push(temp1[i]);
	}
	queue<Node> qu;//將原本的v放進queue
	for (int i = 0;i < v.size();i++) {
		qu.push(v[i]);
	}
	//int cnt1 = 0;
	int cnt2 = 0;//計算print出的分鐘數
	/*
	cout << "temp2: " << endl;
	while (!temp2.empty()) {
		cout << temp2.front()<<" ";
		temp2.pop();
	}
	cout << endl;
	*/
	while(!qu.empty()) { //!!!!!!!!!!!!!!!!!!!!!!改了這!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		if (!qu.empty() && !temp2.empty() && qu.front().val != temp2.front()) {//如果qu.front()不等於temp2.front()
			//就把qu.front()放到最後
			Node tmp = qu.front();
			qu.pop();
			qu.push(tmp);
		}
		else {
			//如果qu.front()等於temp2.front()
			cnt2++;
			if (!qu.empty() && qu.front().pos == m) {//如果是要印出的位置就return分鐘數
				//cout << "m: " << m << endl;//debug
				return cnt2;
			}
			qu.pop();
			temp2.pop();
		}
	}
	return cnt2+1;//!!!!!!!!!!!!!!!!!!!!!!改了這!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
int main() {
	int cases;
	int n, m;
	int level;
	cin >> cases;
	for (int i = 0;i < cases;i++) {
		cin >> n >> m;
		vector<Node> v(n);
		for (int j = 0;j < n;j++) {
			cin >> level;
			v[j].pos = j;
			v[j].val = level;
		}
		for (int j = 0;j < v.size();j++) {
			//cout << v[j].val << " " ;
		}
		//cout << endl;
		cout << sol(v, m) << endl;
	}
}