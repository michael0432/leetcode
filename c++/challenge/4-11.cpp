class Solution {
public:
    int maxi = 0;
    int dfs(TreeNode* root){
        if(!root)
            return 0;
        int l = dfs(root->left);
        int r = dfs(root->right);
        maxi = max(maxi, l + r);
        return max(l, r) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxi;
    }
};