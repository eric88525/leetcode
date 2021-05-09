# point

+ 透過lower_bound 找到 >= house[i] 的 heaters 位置
+ 如果是 heaters [0]  ， 算house跟他的最小距離
+ 如果是 heaters [i+N]， 算 heaters [i+N] 和 heaters [I+N-1] 跟house[i] 的最小距離
+ 依序檢查每個房子跟heaters 的最小距離