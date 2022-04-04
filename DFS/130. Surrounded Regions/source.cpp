class Solution
{
public:
    int row;
    int col;

    void solve(vector<vector<char>> &board)
    {

        row = board.size(), col = board[0].size();

        for (int c = 0; c < col; c++)
        {

            if (board[0][c] == 'O')
                DFS(board, 0, c, 'P');
            if (board[row - 1][c] == 'O')
                DFS(board, row - 1, c, 'P');
        }

        for (int r = 0; r < row; r++)
        {

            if (board[r][0] == 'O')
                DFS(board, r, 0, 'P');
            if (board[r][col - 1] == 'O')
                DFS(board, r, col - 1, 'P');
        }

        for (int r = 0; r < row; r++)
        {
            for (int c = 0; c < col; c++)
            {

                if (board[r][c] == 'O')
                    board[r][c] = 'X';
                else if (board[r][c] == 'P')
                    board[r][c] = 'O';
            }
        }
    }

    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

    void DFS(vector<vector<char>> &board, int r, int c, char sign)
    {

        board[r][c] = sign;
        for (auto d : directions)
        {

            int rNext = r + d[0];
            int cNext = c + d[1];

            if (0 <= rNext && rNext < row && 0 <= cNext && cNext < col && board[rNext][cNext] == 'O')
            {
                DFS(board, rNext, cNext, sign);
            }
        }
    }
};