# 994. Rotting Oranges

+ classic BFS problem
+ use **fresh** to store remain fresh orange
+ for every step ,  let  rotten orange's neighbor  to be rotten and push it into queue
+ if there's no fresh orange,return ans

```cpp
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int row = grid.size() , col = grid[0].size();
        
        
        queue<pair<int,int>> items;
        
        int fresh=0;
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                
                if(grid[i][j] == 2){
                    
                    items.push(  make_pair( i,j  ) );
                    
                }  else if (grid[i][j] == 1){
                    
                    fresh++;
                    
                } 
                
            }
        }
        
        int ans=0;
        
        while( items.size() && fresh){
            ans++;
            int n = items.size();
            
            while(n--){
                
                auto temp = items.front();
                items.pop();
                
                if(  temp.first + 1 < row  && grid[temp.first+1][temp.second] == 1 ){
                    fresh--;
                    grid[temp.first+1][temp.second] = 2;
                    items.push( make_pair( temp.first+1 , temp.second )   );
                } 
                
                 if(  temp.first -1 >= 0  && grid[temp.first-1][temp.second] == 1 ){
                    fresh--;
                    grid[temp.first-1][temp.second] = 2;
                    items.push( make_pair( temp.first-1 , temp.second )   );
                } 
                
                if(  temp.second + 1 < col  && grid[temp.first][temp.second+1] == 1 ){
                    fresh--;
                    grid[temp.first][ temp.second + 1 ] = 2;
                    items.push( make_pair( temp.first, temp.second+1 )   );
                } 
                
                 if(  temp.second -1 >=0  && grid[temp.first][temp.second-1] == 1 ){
                    fresh--;
                    grid[temp.first][temp.second -1 ] = 2;
                    items.push( make_pair( temp.first , temp.second-1 )   );
                } 
            }
              
        }
        
        if(fresh) return -1;
        else return ans;
    }
    
    

};
```

