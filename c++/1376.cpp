class Employee{
public:
    int id;
    int time;
    vector<int> sub;
};

class Solution {
public:

    int dfs(vector<Employee>& alls, int headID){
        if(alls[headID].sub.size() == 0 ) return 0;
        int time = 0;
        for(int i=0 ; i<alls[headID].sub.size() ; i++){
            time = max(dfs(alls, alls[headID].sub[i]), time);
        }
        return time + alls[headID].time;
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<Employee> alls;
        for(int i=0 ; i < n ; i++){
            Employee e;
            e.id = i;
            e.time = informTime[i];
            alls.push_back(e);
        }
        for(int i=0 ; i < n ; i++){
            if(manager[i] != -1) 
                alls[manager[i]].sub.push_back(i);
        }
        return dfs(alls, headID);
    }
};