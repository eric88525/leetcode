# 17. Letter Combinations of a Phone Number

DFS backtracking

1. 建立數字對應字母map

2. 每當碰到新子母，幫string 加上當前字母，並往下DFS
3. 當最後一個字母時，加入答案到 result

```C++
// s 紀錄當前字串
// digits紀錄還有多少字母要排列

void letterDFS(string digits, string s, vector<string> & result) {
	if (!digits.size()) {
		result.push_back(s);
		return;
	}
	char x = digits[0];
	for (auto c : keyboard[x]) {
		letterDFS(digits.substr(1), s + c, result);
	}
}
```
