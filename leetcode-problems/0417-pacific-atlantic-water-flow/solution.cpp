class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> result;
        vector<vector<int>> pacific(m, vector<int>(n, 0));
        vector<vector<int>> atlantic(m, vector<int>(n, 0));
        
        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        
        // DFS helper function
        function<void(int,int,vector<vector<int>>&)> dfs = [&](int r, int c, vector<vector<int>>& ocean) {
            ocean[r][c] = 1;
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if (ocean[nr][nc]) continue;
                if (heights[nr][nc] < heights[r][c]) continue;
                dfs(nr, nc, ocean);
            }
        };
        
        // Run DFS from Pacific (top and left edges)
        for (int i = 0; i < m; i++) dfs(i, 0, pacific);
        for (int j = 0; j < n; j++) dfs(0, j, pacific);
        
        // Run DFS from Atlantic (bottom and right edges)
        for (int i = 0; i < m; i++) dfs(i, n - 1, atlantic);
        for (int j = 0; j < n; j++) dfs(m - 1, j, atlantic);
        
        // Collect cells reachable to both
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    result.push_back({i, j});
            }
        }
        return result;
    }
};

