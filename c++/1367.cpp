class Solution {
public:

    bool dfs(ListNode* head, TreeNode* root){
        if(head == NULL)
            return true;
        if(head != NULL && root == NULL){
            return false;
        }
        if(root->val == head->val){
            return dfs(head->next, root->left) || dfs(head->next, root->right);
        }
        else{
            return false;
        }
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(root == NULL) return false;
        return dfs(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};