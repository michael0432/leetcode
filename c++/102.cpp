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
    vector<vector<int>> v = {};
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return v;
        bfs(root, 0);
        return v;
    }
    void bfs(TreeNode* root , int depth){
        if(v.size() <= depth){
            v.push_back({}); 
        }
        v[depth].push_back(root->val);
        if(root -> left != NULL) bfs(root->left, depth+1);
        if(root -> right != NULL) bfs(root->right, depth+1);
    }
};