
 // Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 

class Solution {
public:
    int total = 0;
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root);
        return total;
    }
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        dfs(root->right);
        if(root->val % 2 == 0){
            if(root->left){
                if(root->left->left) total += root->left->left->val;
                if(root->left->right) total += root->left->right->val;
            }
            if(root->right){
                if(root->right->left) total += root->right->left->val;
                if(root->right->right) total += root->right->right->val;
            }
        }
    }
};