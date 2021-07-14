# 1091. Shortest Path in Binary Matrix

BFS

> 用BFS找出當下的點能往哪邊走(value=0)，走完就記錄要走幾步 & 設為1


```c++
class Solution {
public: 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int row = grid.size(),col = grid[0].size();
        
        if(row ==0 || col == 0) return -1;
        
        if(grid[0][0] != 0 || grid[row-1][col-1] != 0) return -1;
           
        // enum all direction   
        vector<vector<int>> directions = { {0,1} , {1,0} ,{1,1} ,  {-1,-1},{0,-1},{1,-1},{-1,0},{-1,1},};
        
        // first in first out

        queue<pair<int,int>> que;
        que.push(make_pair(0,0));
        
        grid[0][0] = 1;
        
        while(!que.empty()){
            
            auto curr = que.front();
            
            int x = curr.second , y= curr.first;
            
            // the end of the map , return
            if(x == col-1 && y == row-1) return grid[y][x];
            
            // find all possible walkpath
            for(auto direct : directions){
            
                int nx = x + direct[1];
                int ny = y + direct[0];
                
                // make sure x & y in range
                if(   nx>=0 && nx < col   && ny>=0 && ny<row && grid[ny][nx] == 0){ 
                    
                    que.push( make_pair(ny,nx));                    
                    grid[ny][nx] = grid[y][x] + 1;
                }          
            }
            que.pop();
        }
        
        return -1;
    }
};
```

