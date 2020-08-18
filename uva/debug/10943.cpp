#include<iostream>
#include<vector>
using namespace std;
int main() {
	int m, n;

	vector<vector<long long int>> map(202,vector<long long int>(202));
	map[0][0] = 1;
	for (int i = 1;i < 202;i++) {
		map[i][0] = 1;
		//map[i][1] = i;
		for (int j = 1;j < 202;j++) {
			map[i][j] = map[i - 1][j] + map[i - 1][j - 1];
			//cout << map[i][j] << " ";
		}
		//cout << endl;
	}
	while (cin >> m >> n && m != 0 && n != 0) {
		cout << map[m+n-1][n-1] << endl;
	}
}