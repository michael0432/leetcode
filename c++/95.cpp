/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<vector<TreeNode*>>> dp;
    vector<TreeNode*> dfs(int sid, int eid, vector<int>& arr){
        //cout << sid << eid << endl;
        
        if(sid > eid)
            return {nullptr};
        if(!dp[sid][eid].empty())
            return dp[sid][eid];
        vector<TreeNode*> output;
        
        for (int mid = sid; mid <= eid; mid++){
            //node->val = arr[mid];
            auto left = dfs(sid, mid-1, arr);
            auto right = dfs(mid+1, eid, arr);
            for (auto a: left){
                for(auto b: right){
                    TreeNode *n = new TreeNode(arr[mid]);
                    //n->val = arr[mid];
                    n->left = a;
                    n->right = b;
                    output.push_back(n);
                }
            }
        }
        dp[sid][eid] = output;
        return output;
    }

    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return {};
        dp.resize(n, vector<vector<TreeNode*>>(n,vector<TreeNode*>()));
        vector<TreeNode*> v;
        vector<int> arr;
        for (int i = 1; i <= n; i++){
            arr.push_back(i);
        }
        return dfs(0, n - 1, arr);
    }
};