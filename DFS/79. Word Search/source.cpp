class Solution {
public:

	int row, col;

	bool ans = false;

	bool exist(vector<vector<char>>& board, string word) {

        
        row = board.size() , col=board[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if ( board[i][j] == word[0] &&  !ans   ) DFS(board, i, j, word);
			}
		}
		return ans;
	}

	void DFS(vector<vector<char>>& board, int r, int c, string word) {
		        
        if (word.size() == 1  ) {
			ans = true;
			return;
		}  
        
        char temp = board[r][c];
        
        board[r][c] = '#';
        
		word.erase(0,1);
        
		if (r + 1 < row &&  word[0] == board[r + 1][c])    DFS(board, r + 1, c, word);
		if (r - 1 >= 0 && word[0] == board[r - 1][c])    DFS(board, r - 1, c, word);
		if (c + 1 < col &&  word[0] == board[r][c + 1])  DFS(board, r, c + 1, word);
		if (c - 1 >= 0 && word[0] == board[r][c - 1])  DFS(board, r, c - 1, word);
        
        board[r][c] = temp;
        
	}
};