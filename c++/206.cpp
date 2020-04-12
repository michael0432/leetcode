/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *last = nullptr;
        while(cur){
            ListNode *tmp = cur->next;
            cur->next = last;
            last = cur;
            cur = tmp;
        }
        return last;
    }
};