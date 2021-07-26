# 763. Partition Labels

+ greedy

+ 首先記錄每種字母的最後出現位置
```c++
vector<int> endIndex(26, -1);
for (int i = 0; i < s.size(); i++) {
	endIndex[s[i] - 'a'] = i;
}
```

+ 讓 i 從頭跑到尾，更新 endPoint，當 i == endPoint 代表 i 的位置已經是一個片段尾了

```c++
int end = -1, lastEnd = 0;
vector<int> ans;

for (int i = 0; i < s.size(); i++) {
	end = max(end, endIndex[s[i] - 'a']);
	if (i == end) {
		ans.push_back(end - lastEnd + 1);
		lastEnd = end+1;
	}
}
```