# solution

用一個sliding window從左邊往右掃，如果 

1. |新數值-x 的絕對距離| < |window頭-x| 

2. 絕對距離相同但右邊值> window頭

則更新最接近window的last position

