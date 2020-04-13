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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *slow = head, *fast = head, *slow_pre = nullptr;
        while(fast){
            if(n <= 0){
                slow_pre = slow;
                slow = slow->next;
            }
            fast = fast->next;
            n--;
        }
        if(slow == head)
            return head->next;
        slow_pre->next = slow->next;
        return head;
    }
};