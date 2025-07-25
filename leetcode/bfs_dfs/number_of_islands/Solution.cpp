class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        return dfs(grid);
    }

    // DFS
    // Time Complexity O(n * m)
    // Space Complexity O(n * m)
    int dfs(vector<vector<char>>& grid) {
        int count = 0;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == '1') {
                    count++;
                    vector<pair<int, int>> _stack;
                    _stack.push_back({row, col});

                    while (!_stack.empty()) {
                        pair<int, int> _pair = _stack.back();
                        _stack.pop_back();

                        int _row = _pair.first;
                        int _col = _pair.second;

                        if (_row < 0 || _row > grid.size() - 1) {
                            continue;
                        }

                        if (_col < 0 || _col > grid[0].size() - 1) {
                            continue;
                        }

                        if (grid[_row][_col] != '1') {
                            continue;
                        }

                        _stack.push_back({_row - 1, _col});
                        _stack.push_back({_row + 1, _col});
                        _stack.push_back({_row, _col + 1});
                        _stack.push_back({_row, _col - 1});

                        grid[_row][_col] = '2';
                    }
                }
            }
        }

        return count;
    }
}