
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        
        if(!root->left && !root->right){
            if(root->val == target)
                return NULL;
            else
                return root;
        }
        else{
            root->left = removeLeafNodes(root->left, target);
            root->right = removeLeafNodes(root->right, target);
        }
        if(!root->left && !root->right){
            if(root->val == target) return NULL;
            else return root;
        }
        return root;
    }
};