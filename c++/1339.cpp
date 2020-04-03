class Solution {
public:
    int total = 0;
    long long int maxmul = 0;
    
    void getTotal(TreeNode* root){
        if(!root)
            return;
        total += root->val;
        getTotal(root->left);
        getTotal(root->right);
    }
    long long int getAns(TreeNode* root){
        if(!root)
            return 0;
        long long int leftsum = getAns(root->left);
        long long int rightsum = getAns(root->right);
        maxmul = max(maxmul, ((total - leftsum)* leftsum));
        maxmul = max(maxmul, ((total - rightsum)* rightsum));
        return leftsum + rightsum + root->val;
    }
    
    int maxProduct(TreeNode* root) {
        getTotal(root);
        getAns(root);
        return (int)(maxmul % 1000000007);
    }
};