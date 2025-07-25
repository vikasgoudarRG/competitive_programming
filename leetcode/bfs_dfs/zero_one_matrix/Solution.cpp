class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // return dp_algo(mat);
        return bfs(mat);
    }

    // BFS
    // Time Complexity O(n * m)
    // Space Complexity O(n * m)
    vector<vector<int>> bfs(vector<vector<int>>& mat) {
        vector<pair<int, int>> directions = {
            {1, 0}, 
            {-1, 0},
            {0, 1},
            {0, -1}
        };

        int m = mat.size();
        int n = mat[0].size();
        queue<vector<int>> que; // step, row, col
        unordered_set<string> seen;

        for (int row = 0; row < m; ++row) {
            for (int col = 0; col < n; ++col) {
                if (mat[row][col] == 0) {
                    que.push( {0, row, col} );
                    seen.insert(to_string(row) + "*" + to_string(col));
                }
            }
        }
        while (!que.empty()) {
            vector<int> _temp = que.front();
            que.pop();
            int step = _temp[0];
            int row = _temp[1];
            int col = _temp[2];

            for (pair<int, int> dir: directions) {
                int new_row = row + dir.first;
                int new_col = col + dir.second;

                if (new_row < 0 || new_row >= m) {
                    continue;
                }
                if (new_col < 0 || new_col >= n) {
                    continue;
                }
                string key = to_string(new_row) + "*" + to_string(new_col);
                if (seen.count(key) == 0) {
                    seen.insert(key);
                    que.push({step + 1, new_row, new_col});
                    mat[new_row][new_col] = step + 1;
                }
            }
        }
        return mat;

    }

    // DP
    // Time Complexity O(n * m)
    // Space Complexity O(n * m)
    vector<vector<int>> dp_algo(vector<vector<int>>& mat) {
        vector<vector<int>> dp;
        for (vector<int>& row: mat) {
            dp.emplace_back(row.begin(), row.end());
        }

        // top left
        for (int row = 0; row < mat.size(); ++row) {
            for (int col = 0; col < mat[0].size(); ++col) {
                if (dp[row][col] == 0) continue;

                int nearest = INT_MAX - 1;
                if (row - 1 >= 0) {
                    nearest = min(nearest, dp[row-1][col]);
                }
                if (col - 1 >= 0) {
                    nearest = min(nearest, dp[row][col-1]);
                }
                dp[row][col] = nearest + 1;
            }
        }

        // bottom right
        for (int row = mat.size() - 1; row > -1; --row) {
            for (int col = mat[0].size() - 1; col > -1; --col) {
                if (dp[row][col] == 0) continue;

                int nearest = INT_MAX - 1;
                if (row != mat.size() - 1) {
                    nearest = min(nearest, dp[row + 1][col]);
                }
                if (col != mat[0].size() - 1) {
                    nearest = min(nearest, dp[row][col + 1]);
                }

                dp[row][col] = min(dp[row][col], 1 + nearest);
            }
        }

        return dp;
    }
    
}