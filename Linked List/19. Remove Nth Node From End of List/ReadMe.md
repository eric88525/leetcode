# 19. Remove Nth Node From End of List

找出要刪除的 node 前一個位置 count - n ，並讓他指向下下個位置

如果要被抹除的是第一個，直接return first->next

```c++
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
           
        ListNode* ans = head;      
            
        // count nodes
        int count = 0;    
        ListNode* temp=head;
        while(temp){
            temp = temp->next;
            count++;
        }
        
        // remove first
        if ( count == n) return head->next;        
             
        int first = count - n;
        
        ListNode* first_node =NULL;
        ListNode* end_node =NULL;
        
        while(--first) head=head->next;         
        
        head->next = head->next->next;
                      
        return ans;
        
    }
};
```

