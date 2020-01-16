#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> output;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return output;
        inorder(root);
        return output;
    }
    void inorder(TreeNode* root){
        if(root->left != NULL)
            inorder(root->left); 
        if(root->right != NULL)
            inorder(root->right);
        output.push_back(root->val);
    }
};