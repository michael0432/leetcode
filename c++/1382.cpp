
class Solution {
public:
    vector<TreeNode*> arr;
    void dfs(TreeNode* root){
        if(root){
            dfs(root->left);
            arr.push_back(root);
            dfs(root->right);
        }
    }
    TreeNode* rebuild(int sid, int eid){
        if(sid > eid) return NULL;
        TreeNode* root = arr[(sid+eid)/2];
        //root->val = arr[(sid+eid)/2];
        root->left = rebuild(sid, (sid+eid)/2 - 1);
        root->right = rebuild((sid+eid)/2 + 1, eid);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        dfs(root);
        root = rebuild(0, arr.size()-1);
        return root;
    }
};