class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
       long long tot = n*n;
        int s = (tot*(tot+1))/2;
        long long ss = (tot*(tot+1)*(2*tot+1))/6;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                s -= grid[i][j];
                ss -= grid[i][j]*grid[i][j];
            }
        }
        int m = (s + ss/ s) / 2;
        int r = m-s;
        return{r,m};
    }
};
