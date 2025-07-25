class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       // DFS 
       // Time Complexity O(m * n)
       // Space Complexity O(m * n)
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> pacific_visited(m, vector<bool>(n, false));    
        vector<vector<bool>> atlantic_visited(m, vector<bool>(n, false));

        for (int row = 0; row < m; ++row) {
            dfs(heights, row, 0, pacific_visited);
            dfs(heights, row, n - 1, atlantic_visited);
        }

        for (int col = 0; col < n; ++col) {
            dfs(heights, 0, col, pacific_visited);
            dfs(heights, m - 1, col, atlantic_visited);
        }

        vector<vector<int>> ans;
        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (pacific_visited[row][col] && atlantic_visited[row][col]) {
                    ans.push_back({row, col});
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>>& visited) {
        if (visited[row][col]) return;
        visited[row][col] = true;

        if (row != 0) {
            if (heights[row - 1][col] >= heights[row][col]) {
                dfs(heights, row - 1, col, visited);
            }
        }
        if (row != heights.size() - 1) {
            if (heights[row + 1][col] >= heights[row][col]) {
                dfs(heights, row + 1, col, visited);
            }
        }
        if (col != 0) {
            if (heights[row][col - 1] >= heights[row][col]) {
                dfs(heights, row, col - 1, visited);
            }
        }
        if (col != heights[0].size() - 1) {
            if (heights[row][col + 1] >= heights[row][col]) {
                dfs(heights, row, col + 1, visited);
            }
        }

        return;
    }
}