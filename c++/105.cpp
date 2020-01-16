#include <iostream>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_s = 0, pre_e = preorder.size()-1, in_s = 0, in_e = inorder.size()-1;
        TreeNode* root = build(preorder, inorder, pre_s, pre_e, in_s, in_e);
        return root;
    }
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre_s, int pre_e, int in_s, int in_e){
        if(pre_s > pre_e){
            return NULL;
        }
        TreeNode* root = new TreeNode(0);
        int i;
        for(i=in_s ; i<=in_e ; i++){
            if(preorder[pre_s] == inorder[i]) break;
        }
        root->val = inorder[i];
        root->left = build(preorder, inorder, pre_s+1,pre_s+i-in_s,in_s,i-1);
        root->right = build(preorder, inorder, pre_s+i+1-in_s,pre_e,i+1,in_e);
        return root;
    }
};