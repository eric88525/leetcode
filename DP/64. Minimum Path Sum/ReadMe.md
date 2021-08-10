# 64. Minimum Path Sum

經典DP 問題

```c++
dp[i][j] = grid[i][j] + min( dp[i-1][j] ,dp[i][j-1] );
```

邊界可以先設定好

```c++
for(int i=1;i< col ; i++) dp[0][i] = grid[0][i] + dp[0][i-1];         
for(int i=1;i< row ; i++) dp[i][0] = grid[i][0]  + dp[i-1][0];
```

回傳最右下角那一格就好