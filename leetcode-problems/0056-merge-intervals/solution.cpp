class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>merged;
        sort(intervals.begin(), intervals.end());
        for(auto interval: intervals){
            if(merged.empty()||merged.back()[1]<interval[0]){   
                merged.push_back(interval);
            }else{
                merged.back()[1] = max(interval[1], merged.back()[1]); 
            }
        }
        return merged;
    }
};
