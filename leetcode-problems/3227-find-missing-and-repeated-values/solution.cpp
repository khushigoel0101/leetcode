class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        long long N = (long long)n * n;
        long long s = N * (N + 1) / 2;
        long long ssq = N * (N + 1) * (2 * N + 1) / 6;
        //subtract to get s = missing-repeating
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                s -= grid[i][j];
                ssq -= (long long)grid[i][j] * grid[i][j];
            }
        }   
        // s = missing - repeating
        // ssq = missing^2 - repeating^2 = (missing - repeating)(missing + repeating)
        // sum_val = ssq / s = missing + repeating
        long long sum_val = ssq / s;
        
        int missing = (s + sum_val) / 2;
        int repeating = missing - s;
        
        return {repeating, missing};
    }
};
