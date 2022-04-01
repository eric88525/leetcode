# 24

+ 透過遞迴，每次交換前二個Node，並繼續處理剩餘節點

```c++
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        auto ans = helper(head);
        return ans;
    }
    
    ListNode* helper(ListNode* root){
        if(root ==NULL)return NULL;
        auto *nextNode = root->next;
        if (nextNode){
            ListNode* temp = helper(nextNode->next);
            nextNode->next = root;
            root->next = temp;
            return nextNode;
        }else{
            return root;
        } 
    }
    
};
```

