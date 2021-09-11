# 322. Coin Change

輪流檢視手上的硬幣:

+ 如果當前的 (價值i - 當前硬幣c ) + 1 比 dp[i] 還小就更新
+ 檢視價值要從當前硬幣開始

```c++
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> A(amount+1, amount+1);
        A[0] = 0;
        for (int coin : coins) {
            for (int i = coin; i <= amount; i++) {
                A[i] = min(A[i], A[i - coin] + 1);
            }
        }
        return A[amount] > amount ? -1 : A[amount];
    }
};
```


