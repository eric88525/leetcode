# 343. Integer Break



```
class Solution {
public:
	int integerBreak(int n) {

		vector<int> dp(n + 1, 0);

		for (int i = 1; i <= n; i++) {
			dp[i] = i - 1;
			for (int j = 1; j < i; j++) {
				dp[i] = max(dp[i],  j * max(dp[i - j],i-j) );
			}
		}
		return dp[n];
	}
};
```

