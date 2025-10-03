class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        if (m == 0) return 0;
        int n = heightMap[0].size();
        if (n == 0) return 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        // Push boundary cells into min-heap
        for (int i = 0; i < m; i++) {
            pq.push({heightMap[i][0], {i, 0}});
            pq.push({heightMap[i][n-1], {i, n-1}});
            visited[i][0] = visited[i][n-1] = true;
        }
        for (int j = 0; j < n; j++) {
            pq.push({heightMap[0][j], {0, j}});
            pq.push({heightMap[m-1][j], {m-1, j}});
            visited[0][j] = visited[m-1][j] = true;
        }

        int trappedWater = 0;
        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        while (!pq.empty()) {
            auto [h, pos] = pq.top();
            pq.pop();
            int x = pos.first, y = pos.second;

            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx < 0 || nx >= m || ny < 0 || ny >= n || visited[nx][ny]) continue;
                visited[nx][ny] = true;

                // If current boundary is higher, water can be trapped
                trappedWater += max(0, h - heightMap[nx][ny]);

                // Push next cell with max(height, neighbor)
                pq.push({max(h, heightMap[nx][ny]), {nx, ny}});
            }
        }

        return trappedWater;
    }
};

