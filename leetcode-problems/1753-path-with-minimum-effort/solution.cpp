class Solution {
public:
    typedef tuple<int, int, int>t;
    vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        vector<vector<int>> res(m, vector<int>(n,INT_MAX));
        priority_queue<t, vector<t>, greater<t>>pq;

        pq.push({0,0,0});
        res[0][0] = 0;

        while(!pq.empty()){
           auto [diff, x, y] = pq.top();
           pq.pop();
            if(x==m-1 && y==n-1)
            return diff;
            if (diff > res[x][y]) continue;
            for(auto dir: directions){
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if(x_>=0 && x_<m && y_>=0 && y_<n){
                    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
                    if(res[x_][y_]>newDiff){
                        res[x_][y_] = newDiff;
                        pq.push({res[x_][y_], x_, y_});
                    }
                }
            }
        }
        return res[m-1][n-1];
    }
};
