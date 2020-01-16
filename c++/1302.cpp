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
    int deepestLeavesSum(TreeNode* root) {
        vector<int> info = deep_n_sum(root);
        return info[1];
    }
    vector<int> deep_n_sum(TreeNode* root){
        vector<int> right_info;
        vector<int> left_info;
        if(root->left == NULL && root->right == NULL){
            return {1,root->val};
        }
        if(root->left == NULL){
            right_info = deep_n_sum(root->right);
            return {right_info[0]+1,right_info[1]};
        }
        if(root->right == NULL){
            left_info = deep_n_sum(root->left);
            return {left_info[0]+1,left_info[1]};
        }
        left_info = deep_n_sum(root->left);
        right_info = deep_n_sum(root->right);
        if(left_info[0] > right_info[0]) return {left_info[0]+1,left_info[1]};
        if(left_info[0] == right_info[0]) return {left_info[0]+1,left_info[1]+right_info[1]};
        return {right_info[0]+1,right_info[1]};
    }
};