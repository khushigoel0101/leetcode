class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> t(m, vector<int>(n));
        int in =0;
        if(m*n!=original.size()){
            return {};
        }else{
            for(int i =0; i<m; i++){
                for(int j =0; j<n; j++){
                    t[i][j]=original[in];
                    in++;
                }
            }
            return t;
        }
        
    }
};
