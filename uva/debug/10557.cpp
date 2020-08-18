#include<iostream>
#include<vector>
#include<climits>
#include<string>
#include<queue>
#include<unordered_map>
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
	vector<edge> edges ;
};
string ans(vector<node> map,int room) {
	/*for (int i = 0;i < map.size();i++) {
		cout << "map["<<i<<"].pos: " <<map[i].pos << endl;
	}*/
	//int point = 100;
	int s = map.size() - 1;
	//1. 走不走的到終點，如果走的到而且有過正環->走的到
	//2. 如果走的到而且走到的時候能量還是正->走的到
	//3. 走不到

	//step 1: bfs 看能不能走到
	queue<int> q;
	unordered_map<int, bool> mem;
	mem[0] = true;
	q.push(0);
	bool flag = false;
	while (!q.empty()) {
		if (q.front() == room-1) {
			flag = true;
			break;
		}
		for (int x = 0;x < map[q.front()].edges.size();x++) {
			if (mem.count(map[q.front()].edges[x].des) == 0) {
				q.push(map[q.front()].edges[x].des);
			}
			mem[map[q.front()].edges[x].des] = true;
		}
		q.pop();
	}
	if (flag == false) {
		return "hopeless";
	}

	for (int i = 0;i < s;i++) {
		for (int j = 0;j < map.size();j++) {
			for (int k = 0;k < map[j].edges.size();k++) {
				int des_dis = map[map[j].edges[k].des].dis;
				// #### power <= 0 不能往下走
				if(map[j].dis <= 0)
					continue;
				// 改成大於　因為要找走到某點的剩餘能量最大是多少
				if (map[j].dis + map[j].edges[k].weight > des_dis) {
					//point -= map[j].edges[k].weight;
					// if (map[j].dis >= 100) {
					// 	return "hopeless";
					// }
					map[map[j].edges[k].des].dis = map[j].dis + map[j].edges[k].weight;
					
				}
				
			}
		}

	}
	int temp = 0;
	bool cycle = false;
	for (int j = 0;j < map.size();j++) {
		for (int k = 0;k < map[j].edges.size();k++) {
			int des_dis = map[map[j].edges[k].des].dis;
			// #### power <= 0 不能往下走
			if(map[j].dis <= 0)
				continue;
			if (map[j].dis + map[j].edges[k].weight > des_dis) {//進入負環
				queue <int> q;
				unordered_map<int, bool > mem;
				mem[j] = true;
				q.push(j);
				while (!q.empty()) {
					if (q.front()==room-1) {
						cycle = true;
						break;
						//return "winnble";
					}
					for (int i = 0;i < map[q.front()].edges.size();i++) {
						if (mem.count(map[q.front()].edges[i].des) == 0) {
							q.push(map[q.front()].edges[i].des);
						}
						mem[map[q.front()].edges[i].des] = true;
					}
					q.pop();
					// if (map[room - 1].dis < 100) {
					// 	return "winnable";
					// }
				}
			}

		}
		
	}
	//cout <<"point"<< map[map.size() - 1].dis << endl;
	/*if (temp == 2) {
		return "hopeless";
	}
	*/
	if (map[room-1].dis > 0 || cycle)
		return "winnable";
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
			node n;
			n.pos = j;
			if (j == 0) 
			// #### 出發點power是100
				n.dis = 100;
			else 
			// #### 其他點設成min
				n.dis = INT_MIN;
			map[j] = n;
			cin >> energy >> exit_num ;
			if (exit_num != 0) {
				for (int i = 0;i < exit_num;i++) {
					edge e;
					e.weight = energy;
					cin >> exit_room;
				
					e.des = exit_room - 1;
				
					map[j].edges.push_back(e);
					//if (i == 0)
						//num++;
				
				}
				// edge e1;
				// e1.weight = energy;
				// map[j].edges.push_back(e1);
			}
			// else {
			
			
				
			// }
			//cout << "r: "<<r << endl;
		}
		
		cout << ans(map,room) << endl;
		
	}
	
}