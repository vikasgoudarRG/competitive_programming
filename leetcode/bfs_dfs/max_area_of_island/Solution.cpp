class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return dfs(grid);
    }

    // DFS
    // Time Complexity O(n * m)
    // Space Complexity O(n)
    int dfs(vector<vector<int>>& grid) {
        int max_area = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    vector<pair<int, int>> stack;
                    stack.push_back({row, col});
                    int area = 0;
                    while (!stack.empty()) {
                        pair<int, int> _pair = stack.back();
                        stack.pop_back();
                        int _row = _pair.first;
                        int _col = _pair.second;

                        if (_row < 0 || _row > grid.size() - 1) {
                            continue;
                        }
                        if (_col < 0 || _col > grid[0].size() - 1) {
                            continue;
                        }

                        if (grid[_row][_col] != 1) continue;

                        area++;
                        grid[_row][_col] = 2;

                        stack.push_back({_row - 1, _col});
                        stack.push_back({_row + 1, _col});
                        stack.push_back({_row, _col -1});
                        stack.push_back({_row, _col + 1});
                    }
                    max_area = max(area, max_area);
                }

            }
        }
        return max_area;
    }
}