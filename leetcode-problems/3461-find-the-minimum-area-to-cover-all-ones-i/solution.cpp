class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
       
        int x1 = 0;
        int y1 = 0;
        int x2 = INT_MAX;
        int y2 = INT_MAX;

        for(int i =0; i< grid.size(); i++){
            for(int j =0; j<grid[0].size(); j++){
                if(grid[i][j] == 1){
                    x1=max(x1,i);
                    x2=min(x2,i);
                    y1=max(y1,j);
                    y2=min(y2,j);
                }
            }
        }
        return ((x1-x2 + 1)* (y1-y2 + 1));

    }
};
