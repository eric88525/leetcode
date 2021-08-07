# 132. Palindrome Partitioning II

這是一題dp問題，目的是找出最少的切割數來讓每段都是回文

1. 宣告 dp 矩陣來記錄 s 從 i ~ j 是否為回文
2. 在找 min_dp[i] 時， j 從 0 遍歷到 i ，如果 s[j]  ==  s[i] 代表可能產生新的回文 
	+ 如  s[j+1] ~ s[i-1] 是回文的話 ， 代表 s[j] ~ s[i]是新回文， table 記錄起來
	
	  rule <當下的最小切割數是 min_dp[j-1] + 1 ， 因為 j ~ i 是一段回文 ， j 前面是另外好幾段>
	
	+   如 i == j 或是 i 在 j 後面 ， table 記錄起來，並同上述 rule 來更新最小切割數
	
3. 最後回傳 min_dp [-1] 就好







