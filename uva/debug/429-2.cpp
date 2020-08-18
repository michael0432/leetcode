#include<iostream>
#include<string>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
class dic {
public:
	string name;
	vector<dic> friends;
	int pos;
	int color;
};
int bfs(vector<dic> v, string s1, string s2) {
	queue<dic> q;
	//cout << s2 << endl;
	for (int i = 0;i < v.size();i++) {
		if (v[i].name == s1) {
			v[i].color = 1;
			q.push(v[i]);
		}
	}
	int ans = 0;
	while (!q.empty()) {
		//vector<dic> temp;//(temp存size相同的v[i])
		int d = q.size();
		
		for (int k = 0;k < d;k++) {
			if (q.front().name==s2) {
				// ####
				//ans++;
				return ans;
			}
			//cout << ans << " " << q.front().name << endl;
			for (int i = 0;i < q.front().friends.size();i++) {
				int idx = -1;
				for (int x = 0; x < v.size(); x++){
					if(v[x].name == v[q.front().pos].friends[i].name){
						idx = x;
						
						break;
					}
				}
				if (v[idx].color==0) {
					v[idx].color = 1;
					// ####
					q.push(v[idx]);
				}
			}
			q.front().color = 2;
			q.pop();	
		}
		// #### 
		ans++;
		
	}
	return ans;
}
int main() {
	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		//cout << i << endl;
		// ####
		 
		vector<dic> v;
		int num = 0;
		string s;

		while (getline(cin,s) && s != "*") {
			if(s.size() == 0)
				continue;
			dic d;
			d.name = s;
			//cout << d.name << endl;
			d.color = 0;
			d.pos = num;
			v.push_back(d);
			num++;
		}
		
		//如果字數一樣長，就放進temp
		//如果只差一個字，就放進朋友
		// ####
		
		for (int j = 0;j < v.size();j++) {
			for (int k = j+1; k < v.size(); k++){
				
				if(v[j].name.size() == v[k].name.size()){
					int dif = 0;
					for (int x = 0; x < v[j].name.size(); x++){
						if(v[j].name[x] != v[k].name[x])
							dif++;
					}
					if(dif == 1){
						// friend
						
						v[j].friends.push_back(v[k]);
						v[k].friends.push_back(v[j]);
					}
				}
			}
			
		}
		

				// for (int j = 0;j < v.size();i++) {
		// 	vector<dic> temp;
		// 	//cout << "s: " << endl;
		// 	for (int k = 0;k < v.size();k++) {
		// 		if ((j!=k)&&(v[j].name.size() == v[k].name.size())) {
		// 			temp.push_back(v[k]);
		// 		}
		// 	}
		// 	//cout << "dddd" << endl;
		// 	for (int k = 0;k < temp.size();k++) {
		// 		int dif = 0;
		// 		for (int h = 0;h < temp[k].name.size();h++) {
		// 			if (v[j].name[h]!=temp[k].name[h]) {
		// 				dif++;
		// 			}
		// 		}
		// 		if (dif == 0 ) {
		// 			cout << v[j].name << temp[k].name;
		// 			v[j].friends.push_back(temp[k]);
		// 		}
		// 	}
		// }
		

		//string s1;
		// getline(cin, s);
		// getline(cin, s);
		// cout << s << endl;
		
		while (getline(cin, s) && s.size() != 0) {
			int p = s.find_first_of(" ", 0);
			// p = " "
			string s1, s2;
			for (int j = 0;j < p;j++) {
				s1 += s[j];
			}
			// #### j = p -> j = p+1
			for (int j = p+1;j < s.size();j++) {
				s2 += s[j];
			}
			//cout << s1 << s2 << endl;
			cout << s1 << " " << s2 << " " << bfs(v, s1, s2) << endl;
			//getline(cin, s);
		}
		cout << endl;
	}
	/*
	may->pod:
	may->mad
	mad->pad
	pad->

	*/
}