# 417. Pacific Atlantic Water Flow

DFS
https://leetcode.com/problems/pacific-atlantic-water-flow/discuss/1126938/Short-and-Easy-w-Explanation-and-diagrams-or-Simple-Graph-traversals-DFS-and-BFS

+ 找出下雨後，能下到 Pacific 和  Atlantic 的雨水
+ 從海洋邊界開始 DFS， 若下一個高度 > 當前高度就可以連過去
+ 同時檢查 Pacific 和  Atlantic  是否同時為TRUE，加入答案

```cpp
class Solution
{
public:
    int row, col;
    vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> ans;

    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {

        row = heights.size(), col = heights[0].size();
        pacific = atlantic = vector<vector<bool>>(row, vector<bool>(col, false));
        for (int r = 0; r < row; r++)
        {
            DFS(heights, pacific, r, 0);
            DFS(heights, atlantic, r, col - 1);
        }
        for (int c = 0; c < col; c++)
        {
            DFS(heights, pacific, 0, c);
            DFS(heights, atlantic, row - 1, c);
        }
        return ans;
    }

    void DFS(vector<vector<int>> &heights, vector<vector<bool>> &ocean, int r, int c)
    {

        if (ocean[r][c])
            return;

        ocean[r][c] = true;

        if (pacific[r][c] && atlantic[r][c])
            ans.push_back(vector<int>({r, c}));

        if (r + 1 < row && heights[r + 1][c] >= heights[r][c])
            DFS(heights, ocean, r + 1, c);
        if (c + 1 < col && heights[r][c + 1] >= heights[r][c])
            DFS(heights, ocean, r, c + 1);
        if (r - 1 >= 0 && heights[r - 1][c] >= heights[r][c])
            DFS(heights, ocean, r - 1, c);
        if (c - 1 >= 0 && heights[r][c - 1] >= heights[r][c])
            DFS(heights, ocean, r, c - 1);
    }
};
```

