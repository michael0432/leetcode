#include<iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* left = head;
        ListNode* right = head;
        ListNode* tmp = head;
        while(right != NULL && right->next != NULL){
            tmp = left;
            left = left->next;
            right = right->next->next;
        }
        tmp->next = NULL;
        return merge(sortList(head),sortList(left));
    }
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* output = new ListNode(-1);
        ListNode* currentNode = output;
        while(left != NULL && right != NULL){
            if(left->val < right->val){
                currentNode->next = left;
                left = left->next;
            }
            else{
                currentNode->next = right;
                right = right->next;
            }  
            currentNode = currentNode->next;
        }
        if(left != NULL){
            currentNode->next = left;
        }
        if(right != NULL){
            currentNode->next = right;
        }
        return output->next;
    }
};
