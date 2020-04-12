class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> m;
        while(head){
            if(m.count(head) != 0)
                return true;
            m.insert(head);
            head = head->next;
            
        }
        return false;
    }
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                return true;
        }
        return false;
    }
};