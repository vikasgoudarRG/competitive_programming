class Solution {
public:
    // DFS
    // Time Complexity O(n * m)
    // Space Complexity O(n * m)
    void solve(vector<vector<char>>& board) {
        for (int col = 0; col < board[0].size(); ++col) {
            dfs(board, 0, col);
            dfs(board, board.size() -1, col);
        }
        for (int row = 0; row < board.size(); ++row) {
            dfs(board, row, 0);
            dfs(board, row, board[0].size() - 1);
        }

        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == '#') {
                    board[row][col] = 'O';
                }
                else {
                    board[row][col] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board, int row, int col) {
        if (row < 0 || row >= board.size()) return;
        if (col < 0 || col >= board[0].size()) return;
        if (board[row][col] != 'O') return;

        board[row][col] = '#';
        dfs(board, row + 1, col);
        dfs(board, row - 1, col);
        dfs(board, row, col + 1);
        dfs(board, row, col - 1);
    }
}