class Solution {
public:
    int m; int n;
    bool isSafe(int x, int y){
        if(x>=0 && x<m && y>=0 && y<n ){
            return true;
        }
        return false;
    }
    typedef tuple<int, int, int> P;
    vector<vector<int>> directions{{1, 1}, {1, -1}, {-1, 1}, {-1, -1},
                                   {1, 0}, {-1, 0}, {0, -1}, {0, 1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();
        if (m == 0 || n == 0 || grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }
        vector<vector<int>>res(m, vector<int>(n, INT_MAX));
        priority_queue<P, vector<P>, greater<P>> pq;

        pq.push({1, 0, 0});
        res[0][0] = 1;

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();

            for (auto dir : directions) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];
                int dist = 1;

                if (isSafe(x_, y_) && grid[x_][y_] == 0 &&
                    d + dist < res[x_][y_]) {
                    res[x_][y_] = d + dist;
                    pq.push({d + dist, x_, y_ });
                }
            }
        }
        if(res[m-1][n-1]==INT_MAX)
        return -1;

        return res[m-1][n-1];
    }
};
