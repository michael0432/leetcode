class Solution {
public:
    int total = 0;
    int dfs(TreeNode* root, int n, int x){
        if(!root)
            return 0;
        int lsum = dfs(root->left, n, x);
        int rsum = dfs(root->right, n, x);
        if(root->val == x){
            total = max(lsum, max(rsum, n - lsum - rsum - 1));
        }
        return lsum + rsum + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root, n, x);
        return total > n / 2;
    }
};