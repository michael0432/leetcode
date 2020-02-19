#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    unordered_map<int, bool> two;
    Node* connect(Node* root) {
        if(!root) return NULL;
        int t = 2;
        for(int i=0 ; i<15 ; i++){
            two[t-1] = true;
            t *= 2;
        }
        Node* origin_root = root;
        queue<Node*> q;
        q.push(root);
        Node* tmp;
        int cnt = 1;
        while(!q.empty()){
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
            tmp = q.front();
            q.pop();
            if(!q.empty()){
                if(!two[cnt]) tmp -> next = q.front();
                root = q.front();
            }
            cnt += 1;
        }
        return origin_root;
    }
};