class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        int tot = r*c;
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i<r; i++){
            for(int j = 0; j<c; j++){
                int oldi = i*c + j;
                int newi = (oldi + k)%tot;
                int newr = newi/c;
                int newc = newi%c;
                ans[newr][newc] = grid[i][j];
            }
        }
        return ans;

       
    }
};
