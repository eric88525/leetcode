# point 
+ 此題要做出除法 & 偵測循環小數
+ 用map來記錄餘數有沒有出現過，且記錄他的出現位置來快速偵測循環小數

## ex
1. 先對 10(numerator) / 3(denominator) 求出 商 和 餘數(r)
    + 如果沒餘數: return 答案
2. r *= 10
3. 如果r有被記錄過: 找出他在哪出現過，加上 "(" , 回傳答案
4. r / denominator  = 3 ... 1 ， 設a = 3 , b = 1 
5. 記錄 map[r] = i (出現在小數點幾位) 
6. 把a加入到答案 
7. 設 r = b , 跳回->步驟2 , 直到r==0 break 
   
## 特別步驟

+  先把 numerator 和 denominator 取絕對
+  正負號提出
