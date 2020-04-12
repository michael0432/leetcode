class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<int> st1, st2;
        while(l1){
            st1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            st2.push(l2->val);
            l2 = l2->next;
        }
        int cnt = 0, sum = 0;
        ListNode *res = new ListNode(0);
        while(!st1.empty() || !st2.empty()){
            if(!st1.empty()){
                sum += st1.top();
                st1.pop();
            }
                
            if(!st2.empty()){
                sum += st2.top();
                st2.pop();
            }
                
            res->val = sum % 10;
            ListNode *head = new ListNode(sum/10);
            head->next = res;
            res = head;
            sum /= 10;
            
        }
        if(res->val == 0)
            return res->next;
        return res;
    }
};