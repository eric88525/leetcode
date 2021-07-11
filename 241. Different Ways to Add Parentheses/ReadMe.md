# 241. Different Ways to Add Parentheses

## 概念

題目希望我們能解出 "2-1-1" ， 讓括號由左邊跑到右邊，算出多種可能性，例如:

( 2 - 1 ) - 1  或是  2 - ( 1 - 1 )

因此需要將問題分成小部分來解決。

## code

```C++
	vector<int> diffWaysToCompute(string expression) {
        
        // 用來紀錄此運算產生何種結果
		vector<int> res;
        
		for (int i = 0; i < expression.size(); i++) {
            
            // 取得當下符號 並判斷是不是運算元
			char c = expression[i];
            
			if (c == '*' || c == '-' || c == '+') {
				// 分割成小問題
                // EX: 2 - 1 - 1 拆成  FUNC(2) - FUNC( 1 - 1 )
                // 1 - 1 拆成 FUNC(1) - (1)
				vector<int> left = diffWaysToCompute(expression.substr(0, i));
				// i+1 to end
				vector<int> right = diffWaysToCompute(expression.substr(i + 1));
                // 做運算
				for (auto l : left) {
					for (auto r : right) {
						switch (c) {
							case '+':
								res.push_back(l + r);
								break;
							case '-':
								res.push_back(l - r);
								break;
							case '*':
								res.push_back(l*r);
								break;					
						}
					}
				}
			}
		}
        // 代表傳入純數字，像是1 2 3...
		if (res.empty()) { res.push_back(stoi(expression)); }
		return res
```

