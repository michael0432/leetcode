#include<iostream>
#include<vector>
#include<climits>
#include<string>
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
string ans(vector<node> map,int room) {
	for (int i = 0;i < map.size();i++) {
		cout << "map["<<i<<"].pos: " <<map[i].pos << endl;
	}
	int point = 100;
	int s = map.size() - 1;
	for (int i = 0;i < s;i++) {
		for (int j = 0;j < map.size();j++) {
			for (int k = 0;k < map[j].edges.size();k++) {
				int des_dis = map[map[j].edges[k].des].dis;
				if (map[j].dis + map[j].edges[k].weight < des_dis) {
					point -= map[j].edges[k].weight;
					map[map[j].edges[k].des].dis = map[j].dis + map[j].edges[k].weight;
					if (point < 0) {
						return "hopeless";
					}
				}
				if ((j + 1 == room)&&(point>=0)) {
					return "winnable";
				}
			}
		}

	}
	for (int j = 0;j < map.size();j++) {
		for (int k = 0;k < map[j].edges.size();k++) {
			int des_dis = map[map[j].edges[k].des].dis;
			if (map[j].dis + map[j].edges[k].weight < des_dis) {//進入負環
				return "hopeless";
			}

		}
	}
	if (point >= 0) {
		return "winnable";
	}
	else {
		return "hopeless";
	}
}
int main() {
	int room;
	while (cin >> room && room!=-1) {
		//int r = 0;
		//cout << "room" << room<<endl;
		int energy, exit_num, exit_room;
		vector<node> map(room);
		for (int j = 0;j < room;j++) {
			//for (int i = 0;i < room;i++) {
				node n;
				n.pos = j;
				//cout << "n.pos: "<<n.pos << endl;
				if (j == 0) 
					n.dis = 0;
				else 
					n.dis = INT_MAX;
				map[j] = n;
			//}
			cin >> energy >> exit_num ;
			//int num=j;
			for (int i = 0;i < exit_num;i++) {
				
				cin >> exit_room;
				edge e;
				e.weight = energy;
				e.des = exit_room - 1;
				
				map[j].edges.push_back(e);
				//if (i == 0)
					//num++;
				
			}
			//cout << "r: "<<r << endl;
		}
		/*for (int i = 0;i < map.size();i++) {
			cout << "map[" << i << "].pos: " << map[i].pos << endl;
			cout << "map[" << i << "].dis: " << map[i].dis << endl;
			cout << "map[" << i << "].egdes.size(): " << map[i].edges.size() << endl;
			cout << "map[" << i << "].egdes[0].weight: " << map[i].edges[0].weight << endl;
			cout << "map[" << i << "].egdes[0].des: " << map[i].edges[0].des << endl;

			cout << endl;
		}*/
		cout << ans(map,room) << endl;
		//r++;
		//cin >> room;
	}
	
}