class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int> &a, const vector<int> &b) {
            if(a[0] == b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        });
        
        vector<vector<int>> ans = people;
        vector<int> mem(people.size(), 0);
        for (int i = 0; i < mem.size(); i++){
            mem[i] = i;
        }

        for (int i = 0; i < people.size(); i++){
            ans[mem[people[i][1]]] = people[i];
            for (int j = people[i][1]; j < people.size()-1; j++){
                mem[j] = mem[j + 1];
            }
        }
        return ans;
    }
};