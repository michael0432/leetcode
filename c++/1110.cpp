#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<TreeNode*> v;
    unordered_map<int,atomic_bool> m;
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(int i=0 ; i<to_delete.size() ; i++){
            m[to_delete[i]] = true;
        }
        del(root, to_delete, true);
        return v;
    }
    TreeNode* del(TreeNode* root, vector<int>& to_delete, bool isd){
        if(!root) return NULL;
        bool b = false;
        if(m.count(root->val) != 0){
            m.erase(root->val);
            b = true;
        }
        else if(isd){
            v.push_back(root);
        }
        if(root->left){
            root->left = del(root->left, to_delete, b);
        }
        if(root->right){
            root->right = del(root->right, to_delete, b);
        }
        if(b) return NULL;
        return root;
    }
};