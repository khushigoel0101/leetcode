class Solution {
public:
//in grid questions - standard paractice - don't do it in place create separate grid.
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        // Step 1:  row shifts (left shift)
        vector<vector<int>> rowShifted(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int newCol = (j - rowShift[i] + n) % n;
                rowShifted[i][newCol] = grid[i][j];
            }
        }

        // Step 2:  column shifts (upward shift)
        vector<vector<int>> result(n, vector<int>(n));
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                int newRow = (i - colShift[j] + n) % n;
                result[newRow][j] = rowShifted[i][j];
            }
        }

        return result;
    }
};
