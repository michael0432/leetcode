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

    ListNode* findMid(ListNode* head){
        ListNode *fast = head, *slow = head;
        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        
        ListNode *prev = nullptr;
        while(head){
            ListNode *tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next)
            return;
        ListNode *first = head;
        ListNode *mid = findMid(head);
        ListNode *last = reverseList(mid);

        while(first && last){
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = last->next;
            first->next = last;
            last->next = tmp1;
            first = tmp1;
            last = tmp2;
        }
    }
};