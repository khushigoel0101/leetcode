class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> visited(n, vector<int>(n, 0));
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({grid[0][0], 0, 0}); // {height, x, y}
        visited[0][0] = 1;
        
        int directions[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        int time = 0;
        
        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();
            int h = cur[0], x = cur[1], y = cur[2];
            time = max(time, h);
            
            if (x == n-1 && y == n-1) return time;
            
            for (auto &d : directions) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < n && ny < n && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    pq.push({grid[nx][ny], nx, ny});
                }
            }
        }
        
        return -1; // never reached
    }
};

