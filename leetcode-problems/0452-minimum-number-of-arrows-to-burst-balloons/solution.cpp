class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 1;
        sort(points.begin(),points.end(),[](vector<int>&a, vector<int>&b){
           return a[1]<b[1];
        });
        int minend = points[0][1];
        for(auto pt: points){
            if(pt[0]>minend){
                count++;
                minend = pt[1];
            }
        }
        return count;
    }
};
