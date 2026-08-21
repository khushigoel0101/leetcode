class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end()); 
        long long cnt = 0;int n = nums.size();
        for (int i = 0; i < n - 1; i++){
            int min_n = lower - nums[i]; 
            int max_n = upper - nums[i];
            auto left_bound = lower_bound(nums.begin() + i + 1, nums.end(), min_n);
            auto right_bound = upper_bound(nums.begin() + i + 1, nums.end(), max_n);
            cnt += (right_bound - left_bound);
        }
        return cnt;
    }
};
