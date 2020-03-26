class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        vector<int> out;
        if(!root) return out;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            for(int i=0 ; i<size ; i++){
                if(i == size - 1){
                    out.push_back(q.front()->val);
                }
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
        }
        return out;
    }
};