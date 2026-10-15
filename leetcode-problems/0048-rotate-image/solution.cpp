class Solution {
public:
// exchange the [i][j]th element with [j][i]th element
//then reverse each row.
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++)
          for (int j = i + 1; j < n; j++)//only the upper digonal
             swap(matrix[i][j], matrix[j][i]);
        for (int i = 0; i < n; i++)
        reverse(matrix[i].begin(), matrix[i].end());
    }
};
