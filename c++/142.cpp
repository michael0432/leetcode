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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *meetNode = nullptr;
        bool meet = false;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                meetNode = slow;
                meet = true;
                break;
            }   
        }
        if(!meet)
            return meetNode;
        else{
            slow = head;
            while(slow && meetNode){
                
                if(slow == meetNode){
                    break;
                }
                slow = slow->next;
                meetNode = meetNode->next;
            }
            return slow;
        }
    }
};