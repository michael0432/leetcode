#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    
    ListNode* oddEvenList(ListNode* head) {
        ListNode *start = head;
        ListNode *second = head->next;
        ListNode *end = start;
        bool odd = true;
        while(head->next && head->next->next){
            ListNode * tmp = head->next;
            head->next = head->next->next;
            if(odd) end = head->next;
            odd = !odd;
            head = tmp;
        }
        end -> next = second;
        return start;
    }
};