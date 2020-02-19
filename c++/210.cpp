#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> output;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> course_map(numCourses,-1);
        unordered_map<int,vector<int>> course_relation;
        
        for(int i=0 ; i<prerequisites.size() ; i++){
            if(course_relation.count(prerequisites[i][0])) course_relation[prerequisites[i][0]].push_back(prerequisites[i][1]);
            else course_relation[prerequisites[i][0]] = {prerequisites[i][1]};
        }
        for(int i=0 ; i<numCourses ; i++){
            if(!dfs(i, course_map, course_relation)) return {};
        }
        return output;
    }
    bool dfs(int course_id, vector<int>& course_map, unordered_map<int,vector<int>>& course_relation){
        if(course_map[course_id] == 2){
            //finish
            return true;
        }
        if(course_map[course_id] == 1){
            //cycle
            return false;
        }
        course_map[course_id] = 1;
        if(course_relation.count(course_id) == 0){
            course_map[course_id] = 2;
            output.push_back(course_id);
            return true;
        }
        else{
            for(int i=0 ; i<course_relation[course_id].size() ; i++){
                if(dfs(course_relation[course_id][i], course_map, course_relation) == false){
                    return false;
                }
            }
            course_map[course_id] = 2;
            output.push_back(course_id);
            return true;
        }
    }
};