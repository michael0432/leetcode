class Solution {
public:

    bool dfs(TreeNode* root, long lmin, long lmax){
        if(!root)
            return true;
        if(root->val <= lmin || root->val >= lmax){
            return false;
        }
        return dfs(root->left, lmin, root->val) && dfs(root->right, root->val, lmax);
    }


    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }
};