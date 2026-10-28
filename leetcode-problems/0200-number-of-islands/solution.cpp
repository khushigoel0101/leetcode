class Solution {
public:
    typedef pair<int, int>P;
    vector<vector<int>>dir {{-1,0}, {0,-1}, {1,0} , {0,1}};
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int island = 0;
        int n = grid[0].size();
        vector<vector<bool>>visited(m, vector<bool>(n,false));
        for(int i = 0; i<m; i++){
           for(int j = 0; j<n; j++){
            if(grid[i][j] == '1' && !visited[i][j]){
                island++;
                visited[i][j] = 1;
                queue<P>q;
                q.push({i,j});
                while(!q.empty()){
                    P curr = q.front();
                    q.pop();
                    int row = curr.first;
                    int col = curr.second;
                    for(auto d: dir){
                        int new_i = row+d[0];
                        int new_j = col+ d[1];
                        if(new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]=='1' && !visited[new_i][new_j]){
                            visited[new_i][new_j] = 1;
                            q.push({new_i, new_j});
                        }
                    }
                }
            }
           }
        }
        return island;

    }
};
