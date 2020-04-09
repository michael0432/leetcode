class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        unordered_map<string, int> m;
        int output = 0;
        for (int i = 0; i < matrix.size(); i++){
            string s1;
            string s2;
            for (int j = 0; j < matrix[i].size(); j++){
                s1 += to_string(matrix[i][j]);
                s2 += to_string(matrix[i][j] ^ 1);
            }
            if(m.count(s1) == 0){
                m[s1] = 1;
                m[s2] = 1;
            }
            else{
                m[s1]++;
                m[s2]++;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++){
            output = max(output, it->second);
        }
        return output;
    }
};