class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if (!head) return NULL;
        ListNode *fast = head; // 快指針
        ListNode *slow = head; // 慢指針
        
        while( fast->next && fast->next->next ){
            
            fast = fast->next->next;
            slow = slow->next;
            
            if (fast==slow){  
                // reset slow and let it move m step
                slow = head; 
                while( fast != slow){
                   fast=fast->next;
                   slow = slow->next;
                }
                return fast;  
            }                 
        }
        return NULL;   
    }
};
