#include <vector>
#include <iostream>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> v = {};
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return v;
        bfs(root, 0);
        return v;
    }
    void bfs(Node* root, int depth){
        if(v.size() <= depth) v.push_back({});
        v[depth].push_back(root->val);
        for(int i=0 ; i<root->children.size() ; i++){
            bfs(root->children[i], depth+1);
        }
    }
};