class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxv = INT_MIN;
        long long minv = INT_MAX;
        
        for (int i = 0; i < nums.size(); i++) {
            maxv = max((long long)nums[i], maxv);
            minv = min((long long)nums[i], minv);
        }
        
        return (long long)k * (maxv - minv);
    }
};
