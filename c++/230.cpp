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
    vector<int> v = {};
    bool b = false;
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return v[v.size()-1];
    }
    void dfs(TreeNode* root, int k){
        
        if(b == false)
            if(root->left != NULL) dfs(root->left, k);
        if(b == false){
            v.push_back(root->val);
            if(v.size() == k){
                b = true;
                return;
            }
            if(root->right != NULL) dfs(root->right, k);
        }
        return;
    }
};