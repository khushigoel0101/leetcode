class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int d = 0;
        int m = INT_MIN;  
        int a = 0;       
        for (int i = 0; i < n; i++) {
            d = (dimensions[i][0]) * (dimensions[i][0]) +
                (dimensions[i][1]) * (dimensions[i][1]);  
            
            if (d > m) {  
                m = d;
                a = dimensions[i][0] * dimensions[i][1];
            } 
            else if (d == m) {  
                a = max(a, dimensions[i][0] * dimensions[i][1]);
            }
        }
        return a;
    }
};

