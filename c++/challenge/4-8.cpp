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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode *tmp = head;
        while(tmp){
            cnt++;
            tmp = tmp->next;
        }
        int mid = cnt / 2;
        while(mid != 0){
            mid--;
            head = head->next;
        }
        return head;
    }
};