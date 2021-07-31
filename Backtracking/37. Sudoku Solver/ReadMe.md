# 37. Sudoku Solver

運用DFS概念，找出所有可能性

當進入DFS 階段時有3種況:

1. 解完了，標記 solved 為 true
2. 是預設的數字，繼續往下探索
3. 待解決:
   + 枚舉 [1-9] ， 並檢查該數字能否塞入這格，如果可以就填入數字往下一格 DFS
   + DFS完要恢復該格數字為 '.'

```c++
	void DFS(vector<vector<char>>& board, int r, int c) {

		if (r == 9 ) {
			solved = true;
			
		}else if (board[r][c] != '.') {
			DFS(board, r + int((c + 1) / 9), (c + 1) % 9);
		}else {
			for (auto possible : string("987654321")) {

				if (isValid(board, possible, r, c)) {

					board[r][c] = char(possible);

					DFS(board, r + int((c + 1) / 9), (c + 1) % 9);

					if (solved) return;
					board[r][c] = '.';
				}
			}
		}
	}
```

