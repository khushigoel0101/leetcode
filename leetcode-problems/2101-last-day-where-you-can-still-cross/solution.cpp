class Solution {
public:
    int m;
    int n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    bool dfs(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 1) {
            return false;
        }
        if (i == m - 1) {
            return true;
        }
        grid[i][j] = 1;

        for (auto dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];

            if (dfs(new_i, new_j, grid)) {
                return true;
            }
        }
        return false;
    }
    bool cancross(vector<vector<int>>& cells, int mid) {
        vector<vector<int>> grid(m, vector<int>(n));
        for (int i = 0; i <= mid; i++) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;

            grid[x][y] = 1;
        }
        for (int j = 0; j < n; j++) {
            if (grid[0][j] == 0 && dfs(0, j, grid))
                return true;
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        m = row;
        n = col;
        int low = 0, high = cells.size() - 1;
        int lastday = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (cancross(cells, mid)) {
                lastday = mid+1;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return lastday;
    }
};
