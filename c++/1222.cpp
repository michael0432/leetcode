class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
        vector<vector<int>> output;
        for (int i = 0; i < dir.size(); i++){
            vector<int> pos = king;
            while(pos[0] >=0 && pos[0] < 8 && pos[1] >= 0 && pos[1] < 8){
                auto it = find(queens.begin(), queens.end(), pos);
                if(it != queens.end()){
                    output.push_back({queens[it-queens.begin()]});
                    break;
                }
                pos[0] += dir[i][0];
                pos[1] += dir[i][1];
            }
        }
        return output;
    }
};