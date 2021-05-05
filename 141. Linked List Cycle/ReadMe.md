## 概念

+ 宣告快慢指針，快指針走二步，慢指針走一步
+ 兩者相撞 -> 有迴圈
```cpp

while (h1->next  && h1->next->next  ){
            
  h1 = h1->next->next;
  h2 = h2->next;
            
  if (h1==h2){
    return true;
  }
}

```
