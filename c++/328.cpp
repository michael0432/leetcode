#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *end;
    ListNode* oddEvenList(ListNode* head) {
        ListNode *tmp = head->next;
        
        odd(head);
        return head;
    }
    void odd(ListNode* head){
        ListNode *tmp = head->next;
        head->next = head->next->next;
        odd(tmp);  
    }
};