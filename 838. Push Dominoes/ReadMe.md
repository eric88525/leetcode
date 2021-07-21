# 838. Push Dominoes

+ 有兩種情況:

	1. 連續遇到相同子母
 	2. 遇到不同字母

## 相同

L.....L  或是  R....R

那麼這範圍內就得設定成 L

## 不同

R . . . L 或是 R . . L

這兩種情況都只需要補上1點就好，計算方式為中間的點點數量 / 2

```c++
	string pushDominoes(string dominoes) {


        // save last position & last sign
		pair<int, char> lastInfo = make_pair(0, 'L');

		for (int i = 0; i < dominoes.size(); i++) {

			if (dominoes[i] == '.') continue;
			
            // meet two the same dominoes 
			if (dominoes[i] == lastInfo.second) {
				for (int j = lastInfo.first; j < i; j++) {
					dominoes[j] = dominoes[i];
				}
			}
			else if (lastInfo.second == 'R' &&   dominoes[i] == 'L') {
				int range = (i - lastInfo.first - 1) / 2;
				for (int j = 1; j <= range; j++) {
					dominoes[lastInfo.first + j] = 'R';
					dominoes[i - j] = 'L';
				}
			}
			lastInfo = make_pair(i, dominoes[i]);
		}
		if (lastInfo.second == 'R') {
			for (int i = lastInfo.first; i < dominoes.size(); i++) {
				dominoes[i] = 'R';
			}
		}

		return dominoes;
	}
```

