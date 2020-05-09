class Solution {
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> transform = {{1}, {0, 2}, {0, 1, 3, 4}, {2, 4}, {1}};
        vector<int> mem = {1, 1, 1, 1 ,1};
        for (int i = 2; i <= n; i++){
            vector<int> tmp(5, 0);
            for (int j = 0; j < 5; j++){
                for (int k = 0; k < transform[j].size(); k++){
                    tmp[transform[j][k]] += tmp[j];
                }
            }
            mem = tmp;
        }
        int sum = 0;
        for (int i = 0; i < 5; i++){
            sum += tmp[i];
        }
        return sum;
    }
};