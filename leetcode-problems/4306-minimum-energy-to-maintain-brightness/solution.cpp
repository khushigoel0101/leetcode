class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        long long cnt = 0;
        vector<vector<int>>p;
        sort(intervals.begin(), intervals.end());
        for(int i = 0; i<intervals.size(); i++){
            while(( i!=intervals.size()-1 && intervals[i][1]>=intervals[i+1][0] )){
              intervals[i+1][0] = min(intervals[i][0],intervals[i+1][0]);
              intervals[i+1][1] = max(intervals[i][1], intervals[i+1][1]);
              i++;
            }
           p.push_back(intervals[i]);
        }
        long long bulb = ceil(brightness+2)/3;
        for(int i = 0; i<p.size(); i++){
            long long length = (p[i][1] - p[i][0]) + 1;
            cnt = cnt + length;
        }
        long long energy = cnt * bulb;
        return energy; 
    }
    
};
