class Solution {
public:
    
	int row;
	int col;
	vector<pair<int, int>> directions = { {-1,0},{0,-1},{0,1},{1,0} };
    
	int maxAreaOfIsland(vector<vector<int>>& grid) {
		row = grid.size(), col = grid[0].size();
		int maxArea = 0;
		for (int r = 0; r < row; r++) {
			for (int c = 0; c < col; c++) {
				if (!grid[r][c]) continue;
				maxArea = max( maxArea , DFS(grid, r, c));
			}
		}
		return maxArea;
	}


	int DFS(vector<vector<int>>& grid, int r, int c) {
        
		int area = 1;  
		grid[r][c] = 0;
        
		for (auto d : directions) {
            
			int rNext = r + d.first;
			int	cNext = c + d.second;
            
			if (rNext >= 0 && rNext < row  && cNext >= 0 && cNext < col && grid[rNext][cNext]) {
				area += DFS(grid, rNext, cNext);
			}
		}
		return area;
	}

};