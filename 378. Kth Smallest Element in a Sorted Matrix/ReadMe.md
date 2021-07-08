# 378. Kth Smallest Element in a Sorted Matrix

基於binary search

用意是希望找到vector中的某個數 x，<=  x 的數量剛好等於 k

### code


1. 首先找出 left right 可以確保 left & right 是最小和最大，因為題目描述row col 都是遞增排序
```c++
int row = matrix.size(), col = matrix[0].size();
int left = matrix[0][0], right = matrix[row - 1][col - 1], mid;
```
3. 每次 loop 都會檢查 matrix 裡面，<  x 的數字有幾個
4. 依照  binary search ， 中間值不夠大/小就移動 left & right ，當left > right代表收斂成功 ，left是答案。
