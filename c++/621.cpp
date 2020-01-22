#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct MyCompare{
public:
	bool operator()(const pair<char,int> &p1, const pair<char,int> &p2) const{
		return p1.second > p2.second;
	}
};

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> cooltask;
        unordered_map<char,int> tasks_num;
        vector<pair<char,int>> total_sort;
        int cnt = 0;
        for(int i=0 ; i<tasks.size() ; i++){
            if(tasks_num.count(tasks[i]) == 0) tasks_num[tasks[i]] = 1;
            else tasks_num[tasks[i]] += 1;
        }

        for(auto it = tasks_num.begin() ; it != tasks_num.end() ; it++){
            total_sort.push_back({it->first,it->second});
        }
        sort(total_sort.begin(),total_sort.end(),MyCompare());

        while(!tasks_num.empty()){
            for(int i=0 ; i<total_sort.size() ; i++){
                char task = total_sort[i].first;
                if(cooltask.count(task) == 0){
                    // do task
                    tasks_num[task] -= 1;
                    total_sort[i].second -= 1;
                    cooltask[task] = n+1;
                    if(tasks_num[task] == 0){
                        tasks_num.erase(task);
                        total_sort.erase(total_sort.begin()+i);
                    } 
                    break;
                }
            }
            for(auto it = cooltask.begin(); it != cooltask.end() ;){
                it -> second -= 1;
                if(it -> second == 0){
                    cooltask.erase(it++);
                }
                else it++;
            }
            cnt += 1;
            sort(total_sort.begin(),total_sort.end(),MyCompare());
        }  
        return cnt;
    }
};

int main(){
    vector<char> tasks = {'A','A','A','B','B','B'};
    int n = 2;
    Solution s;
    cout << s.leastInterval(tasks, n) << endl;
}