
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (!head) return false;
       
        ListNode *h1 = head; // 快指針
        ListNode *h2 = head; // 慢指針
        
        // 檢驗快指針能否繼續往下走
        while (h1->next  && h1->next->next  ){
            
            h1 = h1->next->next;
          
            // 慢指針一次走一步
            h2 = h2->next;
            
            // 相撞 有迴圈
            if (h1==h2){
                return true;
            }
        }
        
        return false ;
        
    }
};
