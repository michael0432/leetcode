class Solution {
public:

    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> cur, res;
        for (int i = 0; i < A.size(); i++){
            unordered_set<int> tmp = {A[i]};
            for(int x: cur){
                tmp.insert(x | A[i]);
            }
            cur = tmp;
            for(int x:cur){
                res.insert(x);
            }
        }
        return res.size();
    }
};