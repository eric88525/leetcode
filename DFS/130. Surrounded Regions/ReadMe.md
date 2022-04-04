# 130. Surrounded Regions

- DFS

題目希望把矩陣內，不跟邊界相連的 O 都標記為 X

1. 對邊界的 O 做 DFS ， 標記為 P
2. 若矩陣裡不為 P 的點， 設為 X

## CODE

```c++
    void solve(vector<vector<char>>& board) {

        row = board.size() , col = board[0].size();

        for(int c=0;c<col;c++){

            if(board[0][c] == 'O') DFS(board,0,c,'P');
            if(board[row-1][c] == 'O') DFS(board , row-1 , c , 'P');
        }

        for(int r=0;r<row;r++){

            if(board[r][0] == 'O') DFS(board, r , 0,'P');
            if(board[r][col-1] == 'O' ) DFS(board , r ,col-1 , 'P');
        }

        for(int r=0;r<row;r++){
            for(int c =0;c<col;c++){

                if(board[r][c] == 'O') board[r][c] = 'X'  ;
                else  if(board[r][c] == 'P') board[r][c] = 'O'  ;
            }
        }

    }
```
