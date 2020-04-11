class Solution {
public:
    unordered_map<TreeNode *, int> m;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        if(m.count(root) != 0)
            return m[root];
        int val = 0;
        if(root->left){
            val += dfs(root->left->left);
            val += dfs(root->left->right);
        }
        if(root->right){
            val += dfs(root->right->left);
            val += dfs(root->right->right);
        }
        val = max(val + root->val, dfs(root->left) + dfs(root->right));
        
        m[root] = val;
        return val;
    }

    int rob(TreeNode* root) {
        return dfs(root);
    }
};