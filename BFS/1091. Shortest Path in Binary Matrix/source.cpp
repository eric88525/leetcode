class Solution {
public:
    
    
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        int row = grid.size(),col = grid[0].size();
        
        if(row ==0 || col == 0) return -1;
        
        if(grid[0][0] != 0 || grid[row-1][col-1] != 0) return -1;
           
        vector<vector<int>> directions = { {0,1} , {1,0} ,{1,1} ,  {-1,-1},{0,-1},{1,-1},{-1,0},{-1,1},};
        
        
        queue<pair<int,int>> que;
        que.push(make_pair(0,0));
        
        grid[0][0] = 1;
        
        while(!que.empty()){
            
            auto curr = que.front();
            
            int x = curr.second , y= curr.first;
            
            if(x == col-1 && y == row-1) return grid[y][x];
                 
            for(auto direct : directions){
            
                int nx = x + direct[1];
                int ny = y + direct[0];
                       
                
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