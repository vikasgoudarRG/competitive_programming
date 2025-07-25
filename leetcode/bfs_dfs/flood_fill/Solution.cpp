class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int old_color = image[sr][sc];
        if (old_color != color) {
            dfs(image, sr, sc, color, old_color);   
        }
        return image; 
    }

    // DFS
    // Time Complexity O(n * m)
    // Space Complexity O(n * m)
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int old_color) {
        if (sr < 0) return;
        if (sr > image.size() - 1) return;
        if (sc < 0) return;
        if (sc > image[0].size() - 1) return;

        if (image[sr][sc] != old_color) return;
        image[sr][sc] = color;

        dfs(image, sr - 1, sc, color, old_color);
        dfs(image, sr + 1, sc, color, old_color);
        dfs(image, sr, sc + 1, color, old_color);
        dfs(image, sr, sc - 1, color, old_color);
    }
}