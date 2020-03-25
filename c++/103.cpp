#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <algorithm>
using namespace std;

  //Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> output;
        if(!root) return output;
        vector<pair<TreeNode*, int>> v;
        deque<pair<TreeNode*, int>> q2;
        pair<TreeNode*,int> p(root,1);
        //q.push_back(p);
        q2.push_back(p);
        int depth = 2;
        while(!q2.empty()){
            
            if(p.first->left){
                pair<TreeNode*,int> p1(p.first->left,p.second+1);
                //q.push_back(p1);
                q2.push_back(p1);
            } 
            if(p.first->right){
                pair<TreeNode*,int> p2(p.first->right,p.second+1);
                //q.push_back(p2);
                q2.push_back(p2);
            }
            //cout << q2.front().first->val << endl;
            v.push_back(q2.front());
            q2.pop_front();
            p = q2.front();
        }
        //cout << v.size() << endl;
        vector<int> tmp;
        tmp.push_back(v[0].first->val);
        //output.push_back(tmp);
        for(int i=1 ; i<v.size() ; i++){
            if(v[i].second != v[i-1].second){
                if(v[i-1].second % 2 == 0){
                    reverse(tmp.begin(), tmp.end());
                }
                output.push_back(tmp);
                tmp.clear();
            }
            tmp.push_back(v[i].first->val);
        }
        if(v[v.size()-1].second % 2 == 0) reverse(tmp.begin(), tmp.end());
        output.push_back(tmp);
        return output;
    }
};