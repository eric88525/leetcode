# 91. Decode Ways

+ 從後面往回推，找出在每個階段能有的最大組合數 DP[i]
+ 如果 s[i] == 0 ， dp[i] = 0 ， 因為沒有數字組合是由 0 開頭的
+ 如果 s[i] 和 s[i+1] 可以組合成字符，那麼 dp[i] 就要加上 dp[i+2] 
+ DP.size = s.size + 1 ， DP index = S index

```c++
class Solution {
public:
	int numDecodings(string s) {

		vector<int> dp(s.size() + 1, 0);

		int n = s.size();

		dp[n] = 1;
		dp[n - 1] = s[n - 1] == '0' ? 0 : 1;

		for (int i = n - 2; i >= 0; i--) {

			if (s[i] != '0') dp[i] = dp[i + 1];
			else {
				dp[i] = 0;
			}
			if ( s[i]=='1'  ||  (s[i] == '2' && s[i+1] < '7') ) {
				dp[i] += dp[i + 2];
			}
		}
		return dp[0];
	}
};

```

