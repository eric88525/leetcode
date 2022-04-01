# 23
+ 沿用q23的回答，兩兩合併，要怎合併是關鍵
+ 頭尾合併，這樣期望的合併長度最平均
+ 合併完成後，要重新修正一下lists
+ 參考自jserv的教學 [link](https://hackmd.io/@sysprog/c-linked-list)

```c
struct ListNode* mergeTwoLists(struct ListNode* L1 , struct ListNode* L2){
    
    struct ListNode *head;
    struct ListNode **p = &head;
    
    while(L1&&L2){
        if(L1->val<L2->val){
            *p = L1;
            L1 = L1->next;
        }else{
            *p = L2;
            L2=L2->next;
        }
        p = &(*p)->next;
    }
    
    *p = (struct ListNode *)((uintptr_t) L1 | (uintptr_t) L2);
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){

    if (listsSize == 0) return NULL;
    
    while (listsSize > 1){
        for (int i = 0, j = listsSize -1; i < j; i++, j-- )
            lists[i] = mergeTwoLists(lists[i], lists[j]);
        listsSize = (listsSize + 1) / 2;
    }
    return lists[0];
}
```
