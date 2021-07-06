# 435. Non-overlapping Intervals

+ greedy

1.  首先依照結束時間點小到大排序
1. 先記錄第一個時間點的 end

2. 往後面遍歷

   + 沒重疊->更新結束時間點
   + 有重疊的->忽略

