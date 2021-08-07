# 429. N-ary Tree Level Order Traversal

+ N-ary tree 講白點就是 childred < N 的 tree ， 題目希望把每層的點都列出

## 分兩種版本，recursion & queue

### queue

在處理當前節點 x 時，把 x 的 children都加到 queue 後面，同時記錄 x 到這層節點裡面

處理完當前層的所有點後就會開始下一層的處理

### recursion

重複call 自己，用 depth 紀錄層數就好





