# 1091. Shortest Path in Binary Matrix

BFS

> 用BFS找出當下的點能往哪邊走(value=0)，走完就記錄要走幾步 & 設為1


```c++
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
     
        int row = grid.size();
        if(!row) return -1;
        
        int col = grid[0].size();
        if(row == 1 && col == 1) return 1;
        
        if(grid[0][0]) return -1;
        grid[0][0] = 1;
        
        // start from 0,0
        queue<pair<int,int>> que;
        que.push(make_pair(0,0));
        
        // bfs
        while(que.size()){
            int s = que.size();

            while(s--){
                auto now = que.front();
                
                for(int x=-1;x<=1;x++){
                    for(int y=-1;y<=1;y++){  
                		// prevent out of the board
                        int next_x = min(max(0, now.first + x), row-1);
                        int next_y = min(max(0, now.second + y), col-1);
                        
                        if(!grid[next_x][next_y]){
                            // push to bfs que
                            que.push(make_pair(next_x, next_y));
                            grid[next_x][next_y] = grid[now.first][now.second] + 1;
                            if (next_x == row-1 && next_y == col -1)
                                return grid[now.first][now.second] + 1;
                        }
                    }
                }
                que.pop(); 
            }     
        }
        return -1;
    }
};
```

