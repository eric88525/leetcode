# 160

題目要找出 a 和 b在哪個點相交

## 解法

宣告兩個指針從a和b的頭開始持續往下走，如果走完就換到另一邊(a->b , b->a)開始走

原理是把重疊段當作c，那麼 A = a + c， B = b + c

他們最後一定會在第二個 c 點相交

a + c + b + c 

b + c + a + c

## code 

```c++
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        ListNode * a = headA;
        ListNode * b = headB;
      
        while (a!= b){
            if (a){
                a = a->next;
            }else{
                a = headB;
            }
            if (b){
                b = b->next;
            }else{
                b = headA;
            }            
        }
        return a;
    }
};
```

