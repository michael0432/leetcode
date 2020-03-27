class Solution {
public:

    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;
        int max_sum = 0;
        int lvl = 1;
        int max_lvl = 1;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            for(int i=0 ; i<size ; i++){
                sum += q.front().val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            if(sum > max_sum){
                max_sum = sum;
                max_lvl = lvl;
            }
            lvl++;
        }
        return max_lvl;
    }
};