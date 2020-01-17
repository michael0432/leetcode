#include <iostream>
#include <vector>
#include <queue>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(n == NULL) break;
            q.push(n->left);
            q.push(n->right);
        }
        while(!q.empty()){
            TreeNode* n = q.front();
            q.pop();
            if(n != NULL) return false;
        }
        return true;
    }
};