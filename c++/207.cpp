#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> reach = {};
    vector<int> reached = {};
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(int i=0 ; i<numCourses ; i++) reach.push_back({});
        for(int i=0 ; i<prerequisites.size() ; i++){
            reach[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        reached.resize(numCourses,0);
        for(int i=0 ; i<numCourses ; i++){ 
            if(cycleDetect(i)) return false;   
        }
        return true;
    }
    bool cycleDetect(int nodeId){
        if(reached[nodeId] == 1) return true;
        if(reached[nodeId] == 2) return false;
        reached[nodeId] = 1;
        for(int i=0 ; i<reach[nodeId].size() ; i++){
            if(cycleDetect(reach[nodeId][i])) return true;
        }
        reached[nodeId] = 2;
        return false;
    }
};

int main(){
    int n = 4;
    vector<vector<int>> edges = {{0,1},{1,2},{2,3},{3,2}};
    Solution s;
    cout << s.canFinish(n,edges) << endl;
}

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses));
        vector<vector<bool>> visited(numCourses, vector<bool>(numCourses));
        for (int i = 0; i < prerequisites.size(); i++){
            graph[prerequisites[i][1]][prerequisites[i][1]] = 1;
        }
        vector<int> start_node;
        for (int i = 0; i < graph.size(); i++){
            bool b = true;
            for (int j = 0; j < graph[i].size(); j++){
                if(graph[i][j] != 0){
                    b = false;
                    break;
                }
            }
            if(b){
                start_node.push_back(i);
                break;
            }
        }
        if(start_node.size() == 0)
            return false;

        else{
            for
        }
    }
};