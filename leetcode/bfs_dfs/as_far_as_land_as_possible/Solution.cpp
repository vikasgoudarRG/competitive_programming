class Solution {
public:
    // BFS
    // Time Complexity O(n * m)
    // Space Complexity O(n * m)
    int maxDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> que;
        unordered_set<string> seen;

        for (int row = 0; row < m; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) {
                    string key = to_string(row) + "*" + to_string(col);
                    seen.insert(key);
                    que.push({row, col});
                }
            }
        }

        if (que.empty() || que.size() == m * n) return -1;
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        int distance = -1;
        while (!que.empty()) {
            distance++;
            int interval = que.size();

            for (int i = 0; i < interval; ++i) {
                pair<int, int> cell = que.front();
                que.pop();
                int row = cell.first;
                int col = cell.second;

                for (pair<int, int> dir: directions) {
                    int new_row = row + dir.first;
                    int new_col = col + dir.second;
    
                    if (new_row < 0 || new_row >= m) continue;
                    if (new_col < 0 || new_col >= n) continue;
                    string key = to_string(new_row) + "*" + to_string(new_col);
                    if (seen.count(key) == 0) {
                        seen.insert(key);
                        que.push({new_row, new_col});
                    }
                }
            }
        }

        return distance;
    }
}