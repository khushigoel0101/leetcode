class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long n = intervals.size();
        vector<int>starts(n);
        for(int i = 0; i<n; i++){
            starts[i] = intervals[i][0];
        }
        sort(starts.begin(),starts.end());
        long long tot  = n*(n-1)/2;
        long long nonint = 0;
        for(int i = 0; i<n; i++){
            int end = intervals[i][1];
            auto it = upper_bound(starts.begin(),starts.end(),end);
            long long cnt = starts.end()-it;
            nonint += cnt;
        }
        return tot-nonint;
    }
};
