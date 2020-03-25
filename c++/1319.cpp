class Solution {
public:
    vector<int> set;
    int total_set;
    int find(int x){
        return x == set[x] ? x : find(set[x]); 
    }
    void unions(int x, int y){
        set[find(x)] = find(y);
        total_set --;
    }
    bool equal(int x, int y){
        return find(x) == find(y);
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        total_set = n;
        int cycle = 0;
        for(int i=0 ; i<n ; i++){
            set.push_back(i);
        }
        for(int i=0 ; i<connections.size() ; i++){
            if(equal(connections[i][0], connections[i][1])){
                cycle ++;
            }
            else{
                unions(connections[i][0], connections[i][1]);
            }
        }
        if(total_set > cycle+1){
            return -1;
        }
        else{
            return total_set-1;
        }
    }
};