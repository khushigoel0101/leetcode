class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int removals = 0; 
        int prevend = intervals[0][1];
        for(int i = 1; i<intervals.size(); i++){
            int start = intervals[i][0];
            int end = intervals[i][1];
            if(start<prevend){
                removals++;
                prevend = min(end,prevend);
            }else{
                prevend = end;
            }
        }
        return removals;
    }
};
