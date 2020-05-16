/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:

    pair<Node*, Node*> flat(Node* head){
        Node *start = head;
        Node *pre = head;
        while(head){
            if(head->child){
                Node *tmp = head->next;
                pair<Node*, Node*> p = flat(head->child);
                head->next = p.first;
                p.first->prev = head;
                p.second->next = tmp;
                if(tmp) tmp->prev = p.second;
                pre = head;
                head->child = nullptr;
                head = p.second;
            }
            else{
                pre = head;
                head = head->next;
            }
            
        }
        return {start, pre};
    }

    Node* flatten(Node* head) {
        return flat(head).first;
    }
};