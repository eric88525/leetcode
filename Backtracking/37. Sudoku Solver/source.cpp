class Solution {
public:

	bool solved = false;

	void solveSudoku(vector<vector<char>>& board) {

		DFS(board, 0, 0);
	}



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

	bool isValid(vector<vector<char>>& board, char num, int r, int c) {

		for (int i = 0; i < 9; i++) {
			if (board[r][i] == num || board[i][c] == num) return false;
		}
        
		int rBlock = r / 3 * 3;
		int cBlock = c / 3 * 3;

		for (int i = rBlock; i < rBlock + 3; i++) {
			for (int j = cBlock; j < cBlock + 3; j++) {
				if (board[i][j] == num) return false;
			}
		}
		return true;
	}
};