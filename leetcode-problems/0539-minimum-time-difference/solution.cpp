class Solution {
public:
    int findMinDifference(std::vector<std::string>& timePoints) {
        int n = timePoints.size();
        std::vector<int> times(n);
        for (int i = 0; i < n; ++i) {
            int hour = std::stoi(timePoints[i].substr(0, 2));  
            int minute = std::stoi(timePoints[i].substr(3, 2));  
            times[i] = hour * 60 + minute; 
        }
        std::sort(times.begin(), times.end());
        int minDiff = INT_MAX;
        for (int i = 1; i < n; ++i) {
            minDiff = std::min(minDiff, times[i] - times[i - 1]);
        }
        minDiff = std::min(minDiff, times[0] + 1440 - times[n - 1]); 
        
        return minDiff;
    }
};


