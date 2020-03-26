class FindElements {
public:
    unordered_set<int> set;

    FindElements(TreeNode* root) {
        if(root) recover(root, 0);
    }
    
    bool find(int target) {
        return set.count(target);
    }

    void recover(TreeNode* root, int val){
        set.insert(val);
        root->val = val;
        if(root->left) recover(root->left, val * 2 + 1);
        if(root->right) recover(root->right, val * 2 + 2);
    }
};