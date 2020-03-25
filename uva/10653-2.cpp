#include<iostream>
#include<queue>
#include<vector>
#include<climits>
using namespace std;
class Robot {
public:
	vector<int> pos;
	
	int color;
};
void bfs(vector<Robot> map,Robot start,Robot end) {
	queue<Robot> q;
	
	start.color = 1;
	for (int i = 0;i < map.size();i++) {
		if (map[i].pos == start.pos) {
			map[i].color = 1;
		}
	}
	q.push(start);
	int step=0;
	int min_step = INT_MAX;
	while (!q.empty()) {
		
		int s = q.size();
		for (int j = 0;j < s;j++) {
			int a = q.front().pos[1] - 1;//左移
			int b = q.front().pos[1] + 1;//右移
			int c = q.front().pos[0] - 1;//上移
			int d = q.front().pos[0] + 1;//下移
			
			for (int i = 0;i < map.size();i++) {
				
				if ((map[i].pos[1] == a)&&(map[i].pos[0]==q.front().pos[0])) {//左移
					if (map[i].pos == end.pos) {
						cout << step+1 << endl;
						return;
						break;
					}
					if (map[i].color == 0) {
						map[i].color = 1;
						q.push(map[i]);
					}
					//cout << "左移: " << map[i].pos[0] << " " << map[i].pos[1]<<endl;
				}
				if ((map[i].pos[1] == b) && (map[i].pos[0] == q.front().pos[0])) {//右移
					if (map[i].pos == end.pos) {
						cout << step+1 << endl;
						return;
						break;
					}
					if (map[i].color == 0) {
						map[i].color = 1;
						q.push(map[i]);
					}
					//cout << "右移: " << map[i].pos[0] << " " << map[i].pos[1] << endl;
				}
				if ((map[i].pos[0] == c) && (map[i].pos[1] == q.front().pos[1])) {//上移
					if (map[i].pos == end.pos) {
						cout << step+1 << endl;
						return;
						break;
					}
					if (map[i].color == 0) {
						map[i].color = 1;
						q.push(map[i]);
					}
					//cout << "上移: " << map[i].pos[0] << " " << map[i].pos[1] << endl;
				}
				if ((map[i].pos[0] == d) && (map[i].pos[1] == q.front().pos[1])) {//下移
					if (map[i].pos == end.pos) {
						cout << step+1 << endl;
						return;
						break;
					}
					if (map[i].color == 0) {
						map[i].color = 1;
						q.push(map[i]);
					}
					//cout << "下移: " << map[i].pos[0] << " " << map[i].pos[1] << endl;
				}
				
			}/////////////////////////////////////////////////////////////
			//cout << endl;
			for (int i = 0;i < map.size();i++) {
				if ((map[i].pos == q.front().pos)) {
					map[i].color = 2;

				}
			}
			
			q.pop();

		}
		
		
		/*if (q.empty()) {
			cout << "null" << endl;
		}
		else {

			cout << q.front().pos[0] << " " << q.front().pos[1]<<endl;
		}*/
		
		if (min_step>step) {
			min_step = step;
		}
		step++;
	}
	cout << step << endl;
}
int main() {
	int rows, cols, num, bomb_row, bomb_num, bomb_col, srow, scol, erow, ecol;
	cin >> rows >> cols;
	cin >> num;
	vector<Robot> B;
	vector<Robot> map;
	for (int i = 0;i < num;i++) {
		cin >> bomb_row >> bomb_num;
		for (int j = 0;j < bomb_num;j++) {
			Robot bomb;
			cin >> bomb_col;
			bomb.pos.push_back(bomb_row);
			bomb.pos.push_back(bomb_col);
			bomb.color = 2;//黑色，不能走
			B.push_back(bomb);
			map.push_back(bomb);
		}
	}
	for (int i = 0;i < rows;i++) {
		for (int j = 0;j < cols;j++) {
			Robot R;
			R.pos.push_back(i);
			R.pos.push_back(j);
			bool b = false;
			for (int i = 0;i < B.size();i++) {
				if (B[i].pos == R.pos) {
					b = true;
				}
			}
			if (b) {
				R.color = 2;
			}
			else {
				R.color = 0;
				map.push_back(R);
			}
			
		}
	}

	Robot start;
	cin >> srow >> scol;
	start.pos.push_back(srow);
	start.pos.push_back(scol);
	start.color = 0;
	B.push_back(start);
	cin >> erow >> ecol;
	Robot end;
	end.pos.push_back(erow);
	end.pos.push_back(ecol);

	int i, j;
	cin >> i >> j;
	/*for (int i = 0;i < map.size();i++) {
		if (map[i].color == 2) {
			cout << "黑 " << map[i].pos[0] << " " << map[i].pos[1] << endl;
		}
		if (map[i].color == 0) {
			cout << "白 " << map[i].pos[0] << " " << map[i].pos[1] << endl;
		}
	}*/

	if ((i == 0) && (j == 0)) {
		bfs(map,start,end);
	}
}