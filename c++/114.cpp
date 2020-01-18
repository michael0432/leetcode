#include <vector>
#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<TreeNode*> v = {};
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        dfs(root);
        
        for(int i=1 ; i<v.size() ; i++){
            root->right = v[i];
            root->left = NULL;
            root = root->right;
        }
    }
    void dfs(TreeNode* root){
        v.push_back(root);
        if(root->left != NULL) dfs(root->left);
        if(root->right != NULL) dfs(root->right);
    }
};