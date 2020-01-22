#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {    
        ListNode* l3 = new ListNode(0);
        ListNode* tmp = l3;
        int add_cnt = 0;
        while(l1 != NULL && l2 != NULL){
            int value = l1->val + l2->val + add_cnt;
            add_cnt = value / 10;
            value %= 10; 
            tmp->next = new ListNode(value);
            tmp = tmp->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL){
            int value = l1->val + add_cnt;
            add_cnt = value / 10;
            value %= 10;
            tmp->next = new ListNode(value);
            tmp = tmp->next;
            l1 = l1->next;
        }
        while(l2 != NULL){
            int value = l2->val + add_cnt;
            add_cnt = value / 10;
            value %= 10;
            tmp->next = new ListNode(value);
            tmp = tmp->next;
            l2 = l2->next;
        }
        if(add_cnt != 0){
            tmp->next = new ListNode(add_cnt);
        }
        return l3->next;
    }
};